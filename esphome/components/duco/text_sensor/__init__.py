import esphome.codegen as cg
from esphome.components import text_sensor
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_ADDRESS, CONF_VERSION

from .. import CONF_DUCO_ID, DUCO_COMPONENT_SCHEMA

DEPENDENCIES = ["duco"]
CODEOWNERS = ["@kokx"]

CONF_SERIAL = "serial"
CONF_ERROR = "error"
CONF_UPTIME = "uptime"
CONF_NODE_TYPE = "node_type"

duco_ns = cg.esphome_ns.namespace("duco")
DucoSerial = duco_ns.class_("DucoSerial", cg.PollingComponent, text_sensor.TextSensor)
DucoVersion = duco_ns.class_("DucoVersion", cg.PollingComponent, text_sensor.TextSensor)
DucoError = duco_ns.class_("DucoError", cg.PollingComponent, text_sensor.TextSensor)
DucoUptime = duco_ns.class_("DucoUptime", cg.PollingComponent, text_sensor.TextSensor)
DucoNodeType = duco_ns.class_("DucoNodeType", cg.PollingComponent, text_sensor.TextSensor)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.Optional(CONF_SERIAL): cv.ensure_list(
            text_sensor.text_sensor_schema(DucoSerial)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoSerial),
                    cv.Optional(CONF_ADDRESS): cv.int_range(0, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(cv.polling_component_schema("300s"))
            .extend(DUCO_COMPONENT_SCHEMA)
        ),
        cv.Optional(CONF_VERSION): cv.ensure_list(
            text_sensor.text_sensor_schema(DucoSerial)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoVersion),
                    cv.Optional(CONF_ADDRESS): cv.int_range(0, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(cv.polling_component_schema("60s"))
            .extend(DUCO_COMPONENT_SCHEMA)
        ),
        cv.Optional(CONF_NODE_TYPE): cv.ensure_list(
            text_sensor.text_sensor_schema(DucoNodeType)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoNodeType),
                    cv.Optional(CONF_ADDRESS): cv.int_range(0, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(cv.polling_component_schema("300s"))
            .extend(DUCO_COMPONENT_SCHEMA)
        ),
        cv.Optional(CONF_ERROR): cv.ensure_list(
            text_sensor.text_sensor_schema(DucoSerial)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoError),
                    cv.Optional(CONF_ADDRESS): cv.int_range(0, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(cv.polling_component_schema("60s"))
            .extend(DUCO_COMPONENT_SCHEMA)
        ),
        cv.Optional(CONF_UPTIME): cv.ensure_list(
            text_sensor.text_sensor_schema(DucoUptime)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoUptime),
                    cv.Optional(CONF_ADDRESS): cv.int_range(0, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(cv.polling_component_schema("60s"))
            .extend(DUCO_COMPONENT_SCHEMA)
        )
    }
).extend(DUCO_COMPONENT_SCHEMA)

async def to_code(config):
    parent = await cg.get_variable(config[CONF_DUCO_ID])

    if CONF_SERIAL in config:
        for text_sensor_config in config[CONF_SERIAL]:

            var = cg.new_Pvariable(text_sensor_config[CONF_ID])
            await cg.register_component(var, text_sensor_config)

            await text_sensor.register_text_sensor(var, text_sensor_config)

            cg.add(var.set_parent(parent))
            if CONF_ADDRESS in text_sensor_config:
                cg.add(var.set_address(text_sensor_config[CONF_ADDRESS]))
            else:
                cg.add(var.set_address(0))

    if CONF_VERSION in config:
        for text_sensor_config in config[CONF_VERSION]:

            var = cg.new_Pvariable(text_sensor_config[CONF_ID])
            await cg.register_component(var, text_sensor_config)

            await text_sensor.register_text_sensor(var, text_sensor_config)

            cg.add(var.set_parent(parent))
            if CONF_ADDRESS in text_sensor_config:
                cg.add(var.set_address(text_sensor_config[CONF_ADDRESS]))
            else:
                cg.add(var.set_address(1))

    if CONF_NODE_TYPE in config:
        for text_sensor_config in config[CONF_NODE_TYPE]:
            var = cg.new_Pvariable(text_sensor_config[CONF_ID])
            await cg.register_component(var, text_sensor_config)
            await text_sensor.register_text_sensor(var, text_sensor_config)
            cg.add(var.set_parent(parent))
            cg.add(var.set_address(text_sensor_config.get(CONF_ADDRESS, 1)))

    if CONF_ERROR in config:
        for text_sensor_config in config[CONF_ERROR]:

            var = cg.new_Pvariable(text_sensor_config[CONF_ID])
            await cg.register_component(var, text_sensor_config)

            await text_sensor.register_text_sensor(var, text_sensor_config)

            cg.add(var.set_parent(parent))
            if CONF_ADDRESS in text_sensor_config:
                cg.add(var.set_address(text_sensor_config[CONF_ADDRESS]))
            else:
                cg.add(var.set_address(1))

    if CONF_UPTIME in config:
        for text_sensor_config in config[CONF_UPTIME]:
            var = cg.new_Pvariable(text_sensor_config[CONF_ID])
            await cg.register_component(var, text_sensor_config)
            await text_sensor.register_text_sensor(var, text_sensor_config)
            cg.add(var.set_parent(parent))
            if CONF_ADDRESS in text_sensor_config:
                cg.add(var.set_address(text_sensor_config[CONF_ADDRESS]))
            else:
                cg.add(var.set_address(1))

