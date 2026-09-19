#include "reboot.h"

namespace esphome {
namespace duco {

static const char *const TAG = "duco reboot";

void DucoReboot::press_action() {
  if (!this->parent_->is_advanced_features_enabled()) {
    ESP_LOGW(TAG, "Advanced features disabled; reboot action rejected");
    return;
  }

  DucoMessage message;
  message.function = 0x04;
  message.data = {0x00};
  this->parent_->send(message, this);
}

void DucoReboot::receive_response(const DucoMessage &message) {
  if (message.function == 0x05)
    this->parent_->stop_waiting(message.id);
}

}  // namespace duco
}  // namespace esphome
