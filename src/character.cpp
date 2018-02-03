#include "instance/character.hpp"

Character::Character(sf::Texture const &texture, int spriteX, int spriteY,
                     int spriteW, int spriteH, int spriteInitX, int spriteEndX,
                     int spriteInitY, int spriteEndY)
    : SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH),
      AnimatedEntity::AnimatedEntity(spriteInitX, spriteEndX, spriteInitY,
                                     spriteEndY),
      animationTimeHandler(sf::seconds(1.f / 14.f)) {
  this->movement = sf::Vector2f(0, 0);
  facingUp = false;
  facingDown = false;
  facingLeft = false;
  facingRight = false;
  lastFacingPosition = DOWN;
}

Character::Character()
    : SpritedEntity::SpritedEntity(), AnimatedEntity::AnimatedEntity() {}

void Character::controlEntity(sf::Keyboard::Key key, bool release) {
  switch (key) {
  case sf::Keyboard::W:
    facingUp = !release;
    if (release){
        lastFacingPosition = UP;
        this->movement.y = 0;
    }
    else
      this->movement.y = -2;
    break;
  case sf::Keyboard::A:
    facingLeft = !release;
    if (release){
        lastFacingPosition = LEFT;
        this->movement.x = 0;
    }
    else
      this->movement.x = -2;
    break;
  case sf::Keyboard::S:
    facingDown = !release;
    if (release){
        lastFacingPosition = DOWN;
        this->movement.y = 0;
    }
    else
      this->movement.y = 2;
    break;
  case sf::Keyboard::D:
    facingRight = !release;
    if (release){
        lastFacingPosition = RIGHT;
        this->movement.x = 0;
    }
    else
      this->movement.x = 2;
    break;
  }
}

void Character::moveCharacter() { moveSprite(movement); }

void Character::animate() {
    if(this->movement.x == 0.f && this->movement.y == 0.f){
        switch(lastFacingPosition){
        case UP:
            configureSpriteRect(0, 260, 120, 130);
            break;
        case DOWN:
            configureSpriteRect(0, 0, 120, 130);
            break;
        case LEFT:
            configureSpriteRect(0, 130, 120, 130);
            break;
        case RIGHT:
            configureSpriteRect(0, 390, 120, 130);
            break;
        }
    }
  if (facingLeft) {
    if (getSpriteInitX() + this->animationLoopState * 120 >= getSpriteEndX()) {
      this->animationLoopState = 0;
    }

      configureSpriteRect(getSpriteInitX() + animationLoopState * 120,
                          getSpriteInitY() + 130, 120, 130);
      ++this->animationLoopState;
  }

  if (facingRight) {
    if (getSpriteInitX() + this->animationLoopState * 120 >= getSpriteEndX()) {
      this->animationLoopState = 0;
    }

      configureSpriteRect(getSpriteInitX() + animationLoopState * 120,
                          getSpriteInitY() + 390, 120, 130);
      ++this->animationLoopState;
  }

  if (facingDown) {
    if (getSpriteInitX() + this->animationLoopState * 120 >= getSpriteEndX()) {
      this->animationLoopState = 0;
    }

      configureSpriteRect(getSpriteInitX() + animationLoopState * 120,
                          getSpriteInitY(), 120, 130);
      ++this->animationLoopState;
  }

  if (facingUp) {
    if (getSpriteInitX() + this->animationLoopState * 120 >= getSpriteEndX()) {
      this->animationLoopState = 0;
    }

      configureSpriteRect(getSpriteInitX() + animationLoopState * 120,
                          getSpriteInitY() + 260, 120, 130);
      ++this->animationLoopState;
  }
}

TimeHandler &Character::getAnimationTimeHandler() {
  return this->animationTimeHandler;
}
