#include "foxer/scene/components/object/game_object.hpp"

namespace fox {

GameObject::GameObject(sf::Texture const &texture,
                       sf::Vector2i sprite_dimensions,
                       sf::Vector2i sprite_pos_at_tex)
    : SpritedEntity(texture, sprite_dimensions, sprite_pos_at_tex) {}

GameObject::GameObject() {}

} // namespace fox
