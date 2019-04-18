#include "gs2d/scene/components/object/main_object.hpp"

namespace gs {

MainObject::MainObject() {}

MainObject::MainObject(sf::Texture const &texture, float animation_framerate,
                       sf::Vector2i sprite_dimensions,
                       sf::Vector2i sprite_pos_at_tex)
    : GameObject(texture, sprite_dimensions, sprite_pos_at_tex),
      AnimatedEntity(animation_framerate) {}

} // namespace gs
