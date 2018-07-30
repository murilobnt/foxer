#include "instance/character.hpp"

Character::Character(sf::Texture const &texture, int spriteX, int spriteY,
                     int spriteW, int spriteH, int animationInitialXPosition, int animationFinalXPosition,
                     int animationInitialYPosition, int animationFinalYPosition,
                     int animationFramesPerSeconds)
    : AnimatedEntity::AnimatedEntity(
          texture, spriteX, spriteY, spriteW, spriteH, animationInitialXPosition, animationFinalXPosition,
          animationInitialYPosition, animationFinalYPosition, animationFramesPerSeconds) {
  this->movement = sf::Vector2f(0, 0);
  lastFacingPosition = DOWN;
  currentFacingPos = FREE;
  movingUp = false;
  movingDown = false;
  movingLeft = false;
  movingRight = false;
}

Character::Character() : AnimatedEntity::AnimatedEntity() {}

void Character::controlEntity() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    movingLeft = true;
    if(currentFacingPos == FREE)
        currentFacingPos = LEFT;
  }
  else {
    movingLeft = false;
    if(currentFacingPos == LEFT){
      lastFacingPosition = currentFacingPos;
      currentFacingPos = FREE;
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    movingDown = true;
    if(currentFacingPos == FREE)
        currentFacingPos = DOWN;
  }
  else {
    movingDown = false;
    if(currentFacingPos == DOWN){
      lastFacingPosition = currentFacingPos;
      currentFacingPos = FREE;
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    movingRight = true;
    if(currentFacingPos == FREE)
        currentFacingPos = RIGHT;
  }
  else {
    movingRight = false;
    if(currentFacingPos == RIGHT){
      lastFacingPosition = currentFacingPos;
      currentFacingPos = FREE;
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    movingUp = true;
    if(currentFacingPos == FREE)
        currentFacingPos = UP;
  }
  else {
    movingUp = false;
    if(currentFacingPos == UP){
      lastFacingPosition = currentFacingPos;
      currentFacingPos = FREE;
    }
  }

  if(movingLeft)
    this->movement.x = -2;
  if(movingDown)
    this->movement.y = 2;
  if(movingRight)
    this->movement.x = 2;
  if(movingUp)
    this->movement.y = -2;
}

void Character::moveCharacter() {
  moveSprite(movement);
  this->movement.x = 0;
  this->movement.y = 0;
}

void Character::animate() {
  if (this->movement.x == 0.f && this->movement.y == 0.f) {
    switch (lastFacingPosition) {
    case UP:
      configureSpriteRect(0, 260);
      break;
    case DOWN:
      configureSpriteRect(0, 0);
      break;
    case LEFT:
      configureSpriteRect(0, 130);
      break;
    case RIGHT:
      configureSpriteRect(0, 390);
      break;
    }
  }

  switch (currentFacingPos) {
    case LEFT:
      applyAnimation(1);
    break;
    case RIGHT:
      applyAnimation(3);
    break;
    case DOWN:
      applyAnimation(0);
    break;
    case UP:
      applyAnimation(2);
    break;
  }
}
