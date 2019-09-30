#ifndef FOX_MAIN_OBJECT_HPP
#define FOX_MAIN_OBJECT_HPP

#include "foxer/scene/components/control/ib_controlable_entity.hpp"
#include "foxer/scene/components/graphic/animated_entity.hpp"
#include "foxer/scene/components/object/game_object.hpp"

namespace fox {

class MainObject : public IBControlableEntity,
                   public GameObject,
                   public AnimatedEntity {

public:
  MainObject();
  MainObject(sf::Texture const &texture, float animation_framerate,
             sf::Vector2i sprite_dimensions,
             sf::Vector2i sprite_pos_at_tex = sf::Vector2i(0, 0));
};

} // namespace fox

#endif
