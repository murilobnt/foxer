#ifndef FOX_LEVEL_COLLISION_VERIFIER_HPP_
#define FOX_LEVEL_COLLISION_VERIFIER_HPP_

#include "foxer/scene/components/object/game_object.hpp"
#include "foxer/other/helpers/tile_grid.hpp"

namespace fox {

struct CollisionOn {
  bool x = false;
  bool y = false;
};

class LevelCollisionVerifier {
public:
  virtual const
  CollisionOn verify_collision(const GameObject &go,
                               const TileGrid &level_tile_grid) const = 0;
};

}

#endif
