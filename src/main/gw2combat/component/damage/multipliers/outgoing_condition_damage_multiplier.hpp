#ifndef GW2COMBAT_COMPONENT_DAMAGE_OUTGOING_CONDITION_DAMAGE_MULTIPLIER_HPP
#define GW2COMBAT_COMPONENT_DAMAGE_OUTGOING_CONDITION_DAMAGE_MULTIPLIER_HPP

namespace gw2combat::component {

struct outgoing_condition_damage_multiplier {
    double multiplier = 1.0;
    double burning_multiplier = 1.0;
    double bleeding_multiplier = 1.0;
    double confusion_multiplier = 1.0;
    double poison_multiplier = 1.0;
    double torment_multiplier = 1.0;
};

}  // namespace gw2combat::component

#endif  // GW2COMBAT_COMPONENT_DAMAGE_OUTGOING_CONDITION_DAMAGE_MULTIPLIER_HPP
