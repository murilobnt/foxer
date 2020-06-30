#include "foxer/abstract_components/main_object.hpp"

namespace fox {

MainObject::MainObject() {}

MainObject::MainObject(sf::Texture const &texture, const sf::IntRect &rect,
                       float animation_framerate)
    : GameObject(texture, rect),
      AnimatedEntity(animation_framerate) {}

MainObject::MainObject(const sf::Texture &texture, float animation_framerate)
    : GameObject(texture),
      AnimatedEntity(animation_framerate) {}

} // namespace fox
