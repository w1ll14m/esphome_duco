#include "error.h"
#include "error_lookup.h"
#include "../duco.h"
#include <vector>
#include <cstdio>

namespace esphome {
namespace duco {

static const char *const TAG = "duco sensor";

void DucoError::set_address(uint8_t address) { ESP_LOGD(TAG, "Errors: SetAddress %i",address); this->address_ = address; }

void DucoError::setup() {}

void DucoError::update() {
  DucoMessage message;
  message.function = 0x30;
  message.data = {address_, 0x00, 0x00, 0x04};
  this->parent_->send(message, this);
}

float DucoError::get_setup_priority() const {
  // After DUCO
  return setup_priority::BUS - 2.0f;
}

void DucoError::receive_response(const DucoMessage &message) {
  // 0x33 is the terminal ACK for a valid node query with no error payload.
  if (message.function == 0x33) {
    publish_state("No errors");
    this->parent_->stop_waiting(message.id);
    return;
  }

  if (message.function != 0x32)
    return;

  if (message.data.empty()) {
    ESP_LOGW(TAG, "Empty error response");
    this->parent_->stop_waiting(message.id);
    return;
  }

  const uint8_t error_count = message.data[0];
  const size_t expected_size = 1 + static_cast<size_t>(error_count) * 5;
  if (message.data.size() < expected_size) {
    publish_state("No errors");
    this->parent_->stop_waiting(message.id);
    return;
  }

  // We need to verify this but currently I have no nodes where I can force an error state.
  if (error_count == 0) {
    publish_state("No errors");
    this->parent_->stop_waiting(message.id);
    return;
  }

  // for each error
  std::string errors;
  for (size_t index = 0; index < error_count; index++) {
    const size_t offset = 1 + index * 5;
    char code_buffer[13];
    snprintf(code_buffer, sizeof(code_buffer), "E%02u.%02u.%02u", message.data[offset + 1],
             message.data[offset + 2], message.data[offset + 3]);
    const std::string code(code_buffer);

    // check lookup table for known error strings.
    const auto *definition = error_lookup::find(code);
    errors += code;
    errors += "  ";
    errors += definition != nullptr ? definition->description : "Unknown DUCO error";
    errors += '\n';
  }

  publish_state(errors);
  this->parent_->stop_waiting(message.id);
}

}  // namespace duco
}  // namespace esphome
