#include "gs2d_engine/scene/components/object/game_object.hpp"

namespace gs {

GameObject::GameObject(sf::Texture const &texture,
                       sf::Vector2i sprite_pos_at_tex,
                       sf::Vector2i sprite_dimensions)
    : SpritedEntity(texture, sprite_pos_at_tex, sprite_dimensions) {}

GameObject::GameObject() {}

} // namespace gs
