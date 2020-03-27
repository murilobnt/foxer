#ifndef FOX_DEFAULT_LEVEL_COL_VERIFIER_HPP_
#define FOX_DEFAULT_LEVEL_COL_VERIFIER_HPP_

#include "foxer/game/level/level_collision_verifier.hpp"

namespace fox {

class DefaultLevelColVerifier : public LevelCollisionVerifier {
public:
  const
  CollisionOn verify_collision(const GameObject &go,
                               const TileGrid &level_tile_grid) const;
};

}

#endif
