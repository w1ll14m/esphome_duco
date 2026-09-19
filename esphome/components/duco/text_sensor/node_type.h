#pragma once

#include "esphome/components/text_sensor/text_sensor.h"
#include "../duco.h"

namespace esphome {
namespace duco {

class DucoNodeType : public PollingComponent, public text_sensor::TextSensor, public DucoDevice {
 public:
  void setup() override;
  void update() override;
  float get_setup_priority() const override;
  void receive_response(const DucoMessage &message) override;
  void set_address(uint8_t address);

 protected:
  uint8_t address_{1};
};

}  // namespace duco
}  // namespace esphome
