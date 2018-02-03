#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/components/animatedentity.hpp"
#include "gamesimple/components/controlableentity.hpp"
#include "gamesimple/components/spritedentity.hpp"
#include "gamesimple/concrete/timehandler.hpp"
#include "instance/facingposition.hpp"

class Character : public SpritedEntity,
                  public AnimatedEntity,
                  public ControlableEntity {
private:
  sf::Vector2f movement;
  TimeHandler animationTimeHandler;
  FacingPosition lastFacingPosition;
  bool facingUp;
  bool facingDown;
  bool facingLeft;
  bool facingRight;

public:
  Character(sf::Texture const &texture, int spriteX, int spriteY, int spriteW,
            int spriteH, int spriteInitX, int spriteEndX, int spriteInitY,
            int spriteEndY);
  Character();
  void controlEntity(sf::Keyboard::Key key, bool release);
  void moveCharacter();
  void animate();

  TimeHandler &getAnimationTimeHandler();
};

#endif
