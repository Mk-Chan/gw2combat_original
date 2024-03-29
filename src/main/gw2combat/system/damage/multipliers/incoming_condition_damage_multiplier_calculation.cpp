#include "gw2combat/system/system.hpp"

#include "gw2combat/component/character/is_actor.hpp"
#include "gw2combat/component/damage/multipliers/incoming_condition_damage_multiplier.hpp"

namespace gw2combat::system {

void incoming_condition_damage_multiplier_calculation(registry_t& registry, tick_t) {
    registry.view<component::effects_component>().each(
        [&](entity_t entity, const component::effects_component& effects_component) {
            auto& incoming_condition_damage =
                registry.emplace<component::incoming_condition_damage_multiplier>(entity);
            size_t vulnerability_stacks = utils::get_num_stacks_of_effect(
                effects::effect_type::VULNERABILITY, effects_component);
            incoming_condition_damage.multiplier = 1.0 + (double)vulnerability_stacks * 0.01;
        });

    registry.view<component::is_actor>(entt::exclude<component::effects_component>)
        .each([&](entity_t entity) {
            registry.emplace<component::incoming_condition_damage_multiplier>(entity);
        });
}

}  // namespace gw2combat::system
