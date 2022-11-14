#ifndef GW2COMBAT_COMPONENT_GEAR_SIGILS_HPP
#define GW2COMBAT_COMPONENT_GEAR_SIGILS_HPP

#include "gw2combat/types.hpp"

#include "gw2combat/weapon.hpp"

namespace gw2combat::component {

struct sigil_air {
    tick_t cooldown_progress = 3'000;
};
struct sigil_earth {
    tick_t cooldown_progress = 2'000;
};
struct sigil_torment {
    tick_t cooldown_progress = 5'000;
};

struct sigil_geomancy {
    tick_t cooldown_progress = 9'000;
};

struct sigil_smoldering {};

}  // namespace gw2combat::component

#endif  // GW2COMBAT_COMPONENT_GEAR_SIGILS_HPP
