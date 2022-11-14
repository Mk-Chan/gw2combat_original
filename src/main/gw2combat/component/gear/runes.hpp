#ifndef GW2COMBAT_COMPONENT_GEAR_RUNE_RUNE_HPP
#define GW2COMBAT_COMPONENT_GEAR_RUNE_RUNE_HPP

#include "gw2combat/types.hpp"

namespace gw2combat {

enum class rune_type : std::uint32_t
{
    BALTHAZAR,
    SCHOLAR,
    FLAME_LEGION,
};

NLOHMANN_JSON_SERIALIZE_ENUM(rune_type,
                             {
                                 {rune_type::BALTHAZAR, "Rune of Balthazar"},
                                 {rune_type::SCHOLAR, "Rune of Scholar"},
                                 {rune_type::FLAME_LEGION, "Rune of Flame Legion"},
                                 {rune_type::BALTHAZAR, "balthazar"},
                                 {rune_type::SCHOLAR, "scholar"},
                                 {rune_type::FLAME_LEGION, "flame legion"},
                             })

}  // namespace gw2combat

namespace gw2combat::component {

struct rune_component {
    rune_type rune;
};

}  // namespace gw2combat::component

#endif  // GW2COMBAT_COMPONENT_GEAR_RUNE_RUNE_HPP
