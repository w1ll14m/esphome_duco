#pragma once

#include "esphome/components/switch/switch.h"
#include "../duco.h"

namespace esphome {
namespace duco {

class DucoInstallerMode : public Component, public switch_::Switch, public DucoDevice {
 public:
  void write_state(bool state) override;
  void receive_response(const DucoMessage &message) override;

 protected:
  bool requested_state_{false};
};

}  // namespace duco
}  // namespace esphome
