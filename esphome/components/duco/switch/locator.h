#pragma once

#include "esphome/components/switch/switch.h"
#include "../duco.h"

namespace esphome {
namespace duco {

class DucoLocator : public Component, public switch_::Switch, public DucoDevice {
 public:
  void write_state(bool state) override;
  void receive_response(const DucoMessage &message) override;
  void set_address(uint8_t address);

 protected:
  uint8_t address_{1};
};

}  // namespace duco
}  // namespace esphome
