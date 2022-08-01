#ifndef GW2COMBAT_SYSTEM_PROFESSION_PROFESSION_SYSTEMS_HPP
#define GW2COMBAT_SYSTEM_PROFESSION_PROFESSION_SYSTEMS_HPP

#include "gw2combat/system/system.hpp"

#include "gw2combat/component/damage/outgoing_damage_source.hpp"
#include "gw2combat/component/profession_components.hpp"

namespace gw2combat::system {

template <combat_stage stage>
static inline void virtue_of_justice(registry_t& registry, tick_t current_tick) {
    if constexpr (stage != combat_stage::AFTER_INCOMING_STRIKE_DAMAGE_CALCULATION) {
        return;
    }

    registry.view<component::incoming_strike_damage>().each(
        [&](const component::incoming_strike_damage& incoming_strike_damage) {
            for (const auto& strike : incoming_strike_damage.strikes) {
                entity_t damage_source_entity =
                    utils::get_damage_source_entity(strike.source, registry);
                auto virtue_of_justice_ptr =
                    registry.try_get<component::virtue_of_justice>(damage_source_entity);
                if (virtue_of_justice_ptr) {
                    ++virtue_of_justice_ptr->num_unaccounted_hits;
                }
            }
        });

    registry.view<component::effective_attributes, component::virtue_of_justice>().each(
        [&](entity_t entity,
            const component::effective_attributes& effective_attributes,
            component::virtue_of_justice& virtue_of_justice) {
            unsigned int burning_stacks_to_apply =
                virtue_of_justice.num_unaccounted_hits /
                virtue_of_justice.number_of_ticks_for_burning_application;
            if (burning_stacks_to_apply > 0) {
                virtue_of_justice.num_unaccounted_hits %=
                    virtue_of_justice.number_of_ticks_for_burning_application;

                double condition_duration_multiplier =
                    (1.0 + effective_attributes.condition_duration_pct / 100.0);
                auto duration = tick_t{(unsigned int)(2'000.0 * condition_duration_multiplier)};

                auto& outgoing_condition_application =
                    registry.get_or_emplace<component::outgoing_condition_application>(entity);
                outgoing_condition_application.append_burning_effects(
                    effects::burning{entity, current_tick, duration}, burning_stacks_to_apply);

                spdlog::info("tick: {}, entity: {}, outgoing burning from virtue_of_justice",
                             current_tick,
                             utils::get_name(entity, registry));
            }
        });
}

}  // namespace gw2combat::system

#endif  // GW2COMBAT_SYSTEM_PROFESSION_PROFESSION_SYSTEMS_HPP