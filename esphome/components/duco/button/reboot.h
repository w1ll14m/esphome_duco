#pragma once

#include "esphome/components/button/button.h"
#include "../duco.h"

namespace esphome {
namespace duco {

class DucoReboot : public Component, public button::Button, public DucoDevice {
 public:
  void press_action() override;
  void receive_response(const DucoMessage &message) override;
};

}  // namespace duco
}  // namespace esphome
