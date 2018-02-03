#include "instance/character.hpp"

Character::Character(sf::Texture const &texture, int spriteX, int spriteY, int spriteInitX,
          int spriteEndX, int spriteInitY, int spriteEndY)
    : SpritedEntity::SpritedEntity(texture, spriteX, spriteY),
      AnimatedEntity::AnimatedEntity(spriteInitX, spriteInitY, spriteEndX,
                                     spriteEndY) {}

void Character::controlEntity(sf::Keyboard::Key key, bool release) {
    switch(key){
    case sf::Keyboard::W:
        moveSprite(sf::Vector2f(0, -2));
        break;
    case sf::Keyboard::A:
        moveSprite(sf::Vector2f(-2, 0));
        break;
    case sf::Keyboard::S:
        moveSprite(sf::Vector2f(0, 2));
        break;
    case sf::Keyboard::D:
        moveSprite(sf::Vector2f(2, 0));
        break;
    }
}
