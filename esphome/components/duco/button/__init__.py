import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import CONF_ID

from .. import CONF_DUCO_ID, DUCO_COMPONENT_SCHEMA

DEPENDENCIES = ["duco"]
CODEOWNERS = ["@kokx"]

CONF_REBOOT = "reboot"

duco_ns = cg.esphome_ns.namespace("duco")
DucoReboot = duco_ns.class_("DucoReboot", cg.Component, button.Button)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.Optional(CONF_REBOOT): button.button_schema(DucoReboot)
        .extend({cv.GenerateID(): cv.declare_id(DucoReboot)})
        .extend(cv.COMPONENT_SCHEMA)
        .extend(DUCO_COMPONENT_SCHEMA),
    }
).extend(DUCO_COMPONENT_SCHEMA)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_DUCO_ID])

    if CONF_REBOOT in config:
        button_config = config[CONF_REBOOT]
        var = cg.new_Pvariable(button_config[CONF_ID])
        await cg.register_component(var, button_config)
        await button.register_button(var, button_config)
        cg.add(var.set_parent(parent))
