import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import CONF_ADDRESS, CONF_ID

from .. import CONF_DUCO_ID, DUCO_COMPONENT_SCHEMA

DEPENDENCIES = ["duco"]
CODEOWNERS = ["@kokx"]

CONF_LOCATOR = "locator"
CONF_INSTALLER_MODE = "installer_mode"

duco_ns = cg.esphome_ns.namespace("duco")
DucoLocator = duco_ns.class_("DucoLocator", cg.Component, switch.Switch)
DucoInstallerMode = duco_ns.class_("DucoInstallerMode", cg.Component, switch.Switch)


CONFIG_SCHEMA = cv.Schema(
    {
        cv.Optional(CONF_LOCATOR): cv.ensure_list(
            switch.switch_schema(DucoLocator)
            .extend(
                {
                    cv.GenerateID(): cv.declare_id(DucoLocator),
                    cv.Required(CONF_ADDRESS): cv.int_range(1, 68),
                }
            )
            .extend(cv.COMPONENT_SCHEMA)
            .extend(DUCO_COMPONENT_SCHEMA)
        ),
        cv.Optional(CONF_INSTALLER_MODE): switch.switch_schema(DucoInstallerMode)
        .extend({cv.GenerateID(): cv.declare_id(DucoInstallerMode)})
        .extend(cv.COMPONENT_SCHEMA)
        .extend(DUCO_COMPONENT_SCHEMA),
    }
).extend(DUCO_COMPONENT_SCHEMA)


async def to_code(config):
    parent = await cg.get_variable(config[CONF_DUCO_ID])

    if CONF_LOCATOR in config:
        for switch_config in config[CONF_LOCATOR]:
            var = cg.new_Pvariable(switch_config[CONF_ID])
            await cg.register_component(var, switch_config)
            await switch.register_switch(var, switch_config)
            cg.add(var.set_parent(parent))
            cg.add(var.set_address(switch_config[CONF_ADDRESS]))

    if CONF_INSTALLER_MODE in config:
        switch_config = config[CONF_INSTALLER_MODE]
        var = cg.new_Pvariable(switch_config[CONF_ID])
        await cg.register_component(var, switch_config)
        await switch.register_switch(var, switch_config)
        cg.add(var.set_parent(parent))
