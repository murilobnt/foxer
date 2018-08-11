#include "gamesimple/components/animatedentity.hpp"

AnimatedEntity::AnimatedEntity(sf::Texture const &texture, int spriteX,
                               int spriteY, int spriteW, int spriteH,
                               int animationInitialXPosition,
                               int animationFinalXPosition,
                               int animationInitialYPosition,
                               int animationFinalYPosition,
                               float animationFramesPerSecond)
        : SpritedEntity::SpritedEntity(texture, spriteX, spriteY,
                                       spriteW, spriteH),
        animationTimeHandler(sf::seconds(1.f / animationFramesPerSecond)) {
        this->animationInitialXPosition = animationInitialXPosition;
        this->animationFinalXPosition = animationFinalXPosition;
        this->animationInitialYPosition = animationInitialYPosition;
        this->animationFinalYPosition = animationFinalYPosition;

        animationLoopState = 0;
}

AnimatedEntity::AnimatedEntity() {
}

int AnimatedEntity::getAnimationInitialXPosition() const {
        return animationInitialXPosition;
}

int AnimatedEntity::getAnimationFinalXPosition() const {
        return animationFinalXPosition;
}

int AnimatedEntity::getAnimationInitialYPosition() const {
        return animationInitialYPosition;
}

int AnimatedEntity::getAnimationFinalYPosition() const {
        return animationFinalYPosition;
}

TimeHandler &AnimatedEntity::getAnimationTimeHandler() {
        return animationTimeHandler;
}

void AnimatedEntity::applyAnimation(int row) {
        sf::Vector2i spriteDimensions = getSpriteDimensions();
        if (getAnimationInitialXPosition() +
            animationLoopState * spriteDimensions.x >=
            getAnimationFinalXPosition())
                animationLoopState = 0;

        configureSpriteRect(getAnimationInitialXPosition() +
                            animationLoopState * spriteDimensions.x,
                            getAnimationInitialYPosition() +
                            row * spriteDimensions.y);

        ++animationLoopState;
}
