#ifndef FOX_GAME_OBJECT_HPP
#define FOX_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "foxer/scene/components/graphic/sprited_entity.hpp"
#include "foxer/scene/components/object/movable_object.hpp"

namespace fox {

class GameObject : public SpritedEntity, public MovableObject {
public:
  GameObject(sf::Texture const &texture, sf::Vector2i sprite_dimensions,
             sf::Vector2i sprite_pos_at_tex = sf::Vector2i(0, 0));

  GameObject();

  virtual void move(float delta_time) = 0;
  virtual void move() = 0;
};

} // namespace fox

#endif
