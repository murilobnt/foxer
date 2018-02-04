#include "gamesimple/components/animatedentity.hpp"

AnimatedEntity::AnimatedEntity(sf::Texture const &texture, int spriteX,
                               int spriteY, int spriteW, int spriteH,
                               int spriteInitX, int spriteEndX, int spriteInitY,
                               int spriteEndY, float animationFramesPerSecond)
    : SpritedEntity::SpritedEntity(texture, spriteX, spriteY, spriteW, spriteH),
      animationTimeHandler(sf::seconds(1.f / animationFramesPerSecond)) {
  this->spriteInitX = spriteInitX;
  this->spriteEndX = spriteEndX;
  this->spriteInitY = spriteInitY;
  this->spriteEndY = spriteEndY;

  this->animationLoopState = 0;
}

AnimatedEntity::AnimatedEntity() {}

int AnimatedEntity::getSpriteInitX() const { return this->spriteInitX; }

int AnimatedEntity::getSpriteEndX() const { return this->spriteEndX; }

int AnimatedEntity::getSpriteInitY() const { return this->spriteInitY; }

int AnimatedEntity::getSpriteEndY() const { return this->spriteEndY; }

TimeHandler &AnimatedEntity::getAnimationTimeHandler() {
  return this->animationTimeHandler;
}

void AnimatedEntity::applyAnimation(int row) {
  sf::Vector2i spriteDimensions = getSpriteDimensions();
  if (getSpriteInitX() + this->animationLoopState * spriteDimensions.x >=
      getSpriteEndX())
    this->animationLoopState = 0;

  configureSpriteRect(getSpriteInitX() +
                          animationLoopState * spriteDimensions.x,
                      getSpriteInitY() + row * spriteDimensions.y);
  ++this->animationLoopState;
}
