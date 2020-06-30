#include "foxer/abstract_components/game_object.hpp"

namespace fox {

GameObject::GameObject(sf::Texture const &texture, const sf::IntRect& rect)
    : sf::Sprite(texture, rect),
      size(rect.width, rect.height){}

GameObject::GameObject(const sf::Texture &texture)
    : sf::Sprite(texture),
      size(0, 0){}

GameObject::GameObject() {}

void GameObject::setTextureRect(int x, int y){
  if(size.x > 0 && size.y > 0)
    sf::Sprite::setTextureRect(sf::IntRect(x, y, size.x, size.y));
}

} // namespace fox
