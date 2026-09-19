#include "locator.h"

namespace esphome {
namespace duco {

void DucoLocator::set_address(uint8_t address) { this->address_ = address; }

void DucoLocator::write_state(bool state) {
  if (!this->parent_->is_advanced_features_enabled()) {
    ESP_LOGW("duco locator", "Advanced features disabled; locator action rejected");
    this->publish_state(this->state);
    return;
  }

  // ConnBoard locator command: 0x10 {0x04, node address, enabled}.
  DucoMessage message;
  message.function = 0x10;
  message.data = {0x04, this->address_, static_cast<uint8_t>(state)};
  this->parent_->send(message, this);
}

void DucoLocator::receive_response(const DucoMessage &message) {
  if (message.function != 0x12)
    return;

  if (!message.data.empty())
    publish_state(message.data[0] != 0);

  this->parent_->stop_waiting(message.id);
}

}  // namespace duco
}  // namespace esphome
