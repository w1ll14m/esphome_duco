#include "installer_mode.h"

namespace esphome {
namespace duco {

void DucoInstallerMode::write_state(bool state) {
  if (!this->parent_->is_advanced_features_enabled()) {
    ESP_LOGW("duco installer", "Advanced features disabled; installer mode action rejected");
    this->publish_state(this->state);
    return;
  }

  // ConnBoard SetNetworkDucoState: 0x10 {0x00, enabled}.
  this->requested_state_ = state;

  DucoMessage message;
  message.function = 0x10;
  message.data = {0x00, static_cast<uint8_t>(state)};
  this->parent_->send(message, this);
}

void DucoInstallerMode::receive_response(const DucoMessage &message) {
  // Disabling returns 0x11 only; enabling can additionally return 0x12.
  if (message.function != 0x11 && message.function != 0x12 && message.function != 0x13)
    return;

  if (message.function == 0x12 && !message.data.empty()) {
    publish_state(message.data[0] != 0);
  } else {
    publish_state(this->requested_state_);
  }

  this->parent_->stop_waiting(message.id);
}

}  // namespace duco
}  // namespace esphome
