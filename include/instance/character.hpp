#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/components/animatedentity.hpp"
#include "gamesimple/components/controlableentity.hpp"
#include "gamesimple/components/spritedentity.hpp"

class Character : public SpritedEntity,
                  public AnimatedEntity,
                  public ControlableEntity {
public:
  Character(sf::Texture const &texture, int spriteX, int spriteY,
            int spriteInitX, int spriteEndX, int spriteInitY, int spriteEndY);
  void controlEntity(sf::Keyboard::Key key, bool release);
};

#endif
