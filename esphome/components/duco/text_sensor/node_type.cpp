#include "node_type.h"

namespace esphome {
namespace duco {

static const char *const TAG = "duco node type";

void DucoNodeType::setup() {}

void DucoNodeType::set_address(uint8_t address) { this->address_ = address; }

void DucoNodeType::update() {
  DucoMessage message;
  message.function = 0x0C;
  message.data = {0x01, this->address_};
  this->parent_->send(message, this);
}

float DucoNodeType::get_setup_priority() const { return setup_priority::BUS - 2.0f; }

void DucoNodeType::receive_response(const DucoMessage &message) {
  if (message.function != 0x0E)
    return;

  if (message.data.size() < 7) {
    ESP_LOGW(TAG, "Node type response for node %u is too short", this->address_);
  } else if (message.data[0] == 0) {
    publish_state("UNKNOWN");
  } else {
    // 0: Type, 1: NetworkType.  This identifies BSRH as virtual UCRH.
    publish_state(resolve_node_type(message.data[0], message.data[1]));
  }

  this->parent_->stop_waiting(message.id);
}

}  // namespace duco
}  // namespace esphome
