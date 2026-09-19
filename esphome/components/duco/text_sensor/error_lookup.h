#pragma once

#include <string>

namespace esphome {
namespace duco {
namespace error_lookup {

struct Definition {
  const char *code;
  const char *severity;
  const char *description;
  const char *recommended_action;
};

// List generated from service-instructions-error-codes-mechanical-ventilation-DucoBox-Energy-(en).pdf
// See https://www.duco.eu/en/videos-installation-maintenance/service-error-codes
static const Definition ENTRIES[] = {
    {"E01.04.01", "error", "No response from the extractor fan.", "Check and/or replace the extractor fan."},
    {"E03.01.01", "error", "ODA temperature sensor value is too low.", "Check and/or replace the temperature sensor."},
    {"E03.01.02", "error", "ODA temperature sensor value is too high.", "Check and/or replace the temperature sensor."},
    {"E03.01.03", "error", "ODA temperature sensor cannot be read.", "Check and/or replace the temperature sensor."},
    {"E03.01.04", "error", "ODA temperature sensor value is unchanged for too long.", "Check and/or replace the temperature sensor."},
    {"E03.01.05", "error", "ODA temperature sensor is short-circuited.", "Check and/or replace the temperature sensor."},
    {"E03.01.06", "error", "ODA temperature sensor has a bad connection.", "Check and/or replace the temperature sensor."},
    {"E04.01.01", "error", "ETA temperature sensor value is too low.", "Check and/or replace the temperature sensor."},
    {"E04.01.02", "error", "ETA temperature sensor value is too high.", "Check and/or replace the temperature sensor."},
    {"E04.01.03", "error", "ETA temperature sensor cannot be read.", "Check and/or replace the temperature sensor."},
    {"E04.01.04", "error", "ETA temperature sensor value is unchanged for too long.", "Check and/or replace the temperature sensor."},
    {"E04.01.05", "error", "ETA temperature sensor is short-circuited.", "Check and/or replace the temperature sensor."},
    {"E04.01.06", "error", "ETA temperature sensor has a bad connection.", "Check and/or replace the temperature sensor."},
    {"E06.01.01", "error", "EHA temperature sensor value is too low.", "Check and/or replace the temperature sensor."},
    {"E06.01.02", "error", "EHA temperature sensor value is too high.", "Check and/or replace the temperature sensor."},
    {"E06.01.03", "error", "EHA temperature sensor cannot be read.", "Check and/or replace the temperature sensor."},
    {"E06.01.04", "error", "EHA temperature sensor value is unchanged for too long.", "Check and/or replace the temperature sensor."},
    {"E06.01.05", "error", "EHA temperature sensor is short-circuited.", "Check and/or replace the temperature sensor."},
    {"E06.01.06", "error", "EHA temperature sensor has a bad connection.", "Check and/or replace the temperature sensor."},
    {"E16.01.01", "error", "Extract air pressure sensor value is too low.", "Check and/or replace the extract air pressure sensor."},
    {"E16.01.02", "error", "Extract air pressure sensor value is too high.", "Check and/or replace the extract air pressure sensor."},
    {"E16.01.03", "error", "Extract air pressure sensor cannot be read.", "Check and/or replace the extract air pressure sensor."},
    {"E16.01.04", "error", "Extract air pressure sensor value is unchanged for too long.", "Check and/or replace the extract air pressure sensor."},
    {"E16.01.05", "error", "Extract air pressure sensor is short-circuited.", "Check and/or replace the extract air pressure sensor."},
    {"E16.01.06", "error", "Extract air pressure sensor has a bad connection.", "Check and/or replace the extract air pressure sensor."},
    {"E28.04.01", "error", "No response from the supply fan.", "Check and/or replace the supply fan."},
    {"E29.01.01", "error", "Supply air pressure sensor value is too low.", "Check and/or replace the supply air pressure sensor."},
    {"E29.01.02", "error", "Supply air pressure sensor value is too high.", "Check and/or replace the supply air pressure sensor."},
    {"E29.01.03", "error", "Supply air pressure sensor cannot be read.", "Check and/or replace the supply air pressure sensor."},
    {"E29.01.04", "error", "Supply air pressure sensor value is unchanged for too long.", "Check and/or replace the supply air pressure sensor."},
    {"E29.01.05", "error", "Supply air pressure sensor is short-circuited.", "Check and/or replace the supply air pressure sensor."},
    {"E29.01.06", "error", "Supply air pressure sensor has a bad connection.", "Check and/or replace the supply air pressure sensor."},
    {"E30.01.01", "error", "SUP temperature sensor value is too low.", "Check and/or replace the temperature sensor."},
    {"E30.01.02", "error", "SUP temperature sensor value is too high.", "Check and/or replace the temperature sensor."},
    {"E30.01.03", "error", "SUP temperature sensor cannot be read.", "Check and/or replace the temperature sensor."},
    {"E30.01.04", "error", "SUP temperature sensor value is unchanged for too long.", "Check and/or replace the temperature sensor."},
    {"E30.01.05", "error", "SUP temperature sensor is short-circuited.", "Check and/or replace the temperature sensor."},
    {"E30.01.06", "error", "SUP temperature sensor has a bad connection.", "Check and/or replace the temperature sensor."},
    {"E31.19.01", "warning", "Filters need replacement.", "See the maintenance instructions."},
    {"E32.10.01", "warning", "Outdoor temperature is too low; ventilation is off for 8 hours.", nullptr},
    {"E33.10.01", "error", "Outdoor temperature is too low; ventilation is permanently off.", "Restart the DucoBox later."},
    {"E35.17.01", "error", "Temperature sensor value is too low.", nullptr},
    {"E35.17.02", "error", "Temperature sensor value is too high.", nullptr},
    {"E35.17.03", "error", "Temperature sensor cannot be read.", nullptr},
    {"E36.24.01", "error", "Connection to the weather station has been lost.", "Check the connection."},
    {"E36.24.02", "error", "Connection to the outdoor temperature sensor has been lost.", "Check the connection."},
    {"E37.17.01", "error", "CO2 sensor value is too low.", "Check and/or replace the user controller or room sensor."},
    {"E37.17.02", "error", "CO2 sensor value is too high.", "Check and/or replace the user controller or room sensor."},
    {"E37.17.03", "error", "CO2 sensor cannot be read.", "Check and/or replace the user controller or room sensor."},
    {"E40.17.01", "error", "Humidity sensor value is too low.", "Check and/or replace the user controller or room sensor."},
    {"E40.17.02", "error", "Humidity sensor value is too high.", "Check and/or replace the user controller or room sensor."},
    {"E40.17.03", "error", "Humidity sensor cannot be read.", "Check and/or replace the user controller or room sensor."},
    {"E42.22.01", "error", "Too many valves are connected.", "Check the maximum number in the DucoBox Energy installation manual."},
    {"E42.22.02", "error", "Too few valves are connected; at least two are required.", "Check the DucoBox Energy installation manual."},
    {"E43.23.01", "warning", "Flow adjustment has not happened or failed.", "Run the adjustment again."},
    {"E43.23.02", "warning", "The requested flow rate cannot be achieved.", "Check the complete installation."},
    {"E44.06.01", "error", "No connection to the Duco Pre-Heater.", "Check the connection."},
    {"E44.06.02", "error", "A Duco Pre-Heater is connected but not configured.", "Configure the Duco Pre-Heater in settings."},
};

inline const Definition *find(const std::string &code) {
  for (const auto &entry : ENTRIES) {
    if (code == entry.code)
      return &entry;
  }
  return nullptr;
}

}  // namespace error_lookup
}  // namespace duco
}  // namespace esphome
