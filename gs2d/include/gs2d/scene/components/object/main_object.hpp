#ifndef GS_MAIN_OBJECT_HPP
#define GS_MAIN_OBJECT_HPP

#include "gs2d/scene/components/control/ib_controlable_entity.hpp"
#include "gs2d/scene/components/graphic/animated_entity.hpp"
#include "gs2d/scene/components/object/game_object.hpp"

namespace gs {

class MainObject : public IBControlableEntity,
                   public GameObject,
                   public AnimatedEntity {

public:
  MainObject();
  MainObject(sf::Texture const &texture, float animation_framerate,
             sf::Vector2i sprite_dimensions,
             sf::Vector2i sprite_pos_at_tex = sf::Vector2i(0, 0));
};

} // namespace gs

#endif
