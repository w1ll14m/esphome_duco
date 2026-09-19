#include "uptime.h"

namespace esphome {
namespace duco {

static const char *const TAG = "duco uptime";

void DucoUptime::setup() {}

void DucoUptime::update() {
  DucoMessage message;
  message.function = 0x10;
  message.data = {0x01, address_, 0x00, 0x49, 0x04};
  this->parent_->send(message, this);
}

float DucoUptime::get_setup_priority() const { return setup_priority::BUS - 2.0f; }

void DucoUptime::receive_response(const DucoMessage &message) {
  if (message.function != 0x12)
    return;

  if (message.data.size() >= 10) {
    uint16_t uptime_minutes = (message.data[9] << 8) + message.data[8];
    uint16_t days = uptime_minutes / 1440;
    uint8_t hours = (uptime_minutes % 1440) / 60;
    uint8_t minutes = uptime_minutes % 60;

    char formatted[24];
    snprintf(formatted, sizeof(formatted), "%ud %uh %um", days, hours, minutes);
    publish_state(formatted);
  } else {
    ESP_LOGW(TAG, "Uptime response for node %u is too short", address_);
  }

  this->parent_->stop_waiting(message.id);
}

void DucoUptime::set_address(uint8_t address) { this->address_ = address; }

}  // namespace duco
}  // namespace esphome
