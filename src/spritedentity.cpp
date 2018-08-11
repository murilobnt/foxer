#include "gamesimple/components/spritedentity.hpp"

SpritedEntity::SpritedEntity(sf::Texture const &texture, int spriteX,
                             int spriteY, int spriteW, int spriteH)
        : spriteDimensions(spriteW, spriteH) {
        sprite.setTexture(texture);
        configureSpriteRect(spriteX, spriteY, spriteW, spriteH);
}

SpritedEntity::SpritedEntity() {
}

void SpritedEntity::configureSpriteRect(int x, int y, int w, int h) {
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::configureSpriteRect(int x, int y) {
        int w = spriteDimensions.x;
        int h = spriteDimensions.y;
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::setSpritePosition(sf::Vector2f position) {
        sprite.setPosition(position);
}

void SpritedEntity::setSpritePosition(float x, float y) {
        sprite.setPosition(x, y);
}

void SpritedEntity::setSpriteScale(float x, float y) {
        sprite.setScale(x, y);
}

void SpritedEntity::moveSprite(sf::Vector2f movement) {
        sprite.move(movement);
}

void SpritedEntity::setSpriteColor(sf::Color color) {
        sprite.setColor(color);
}

sf::Sprite SpritedEntity::getSprite() const {
        return sprite;
}

sf::Vector2f SpritedEntity::getSpritePosition() const {
        return sprite.getPosition();
}

sf::Vector2i SpritedEntity::getSpriteDimensions() const {
        return spriteDimensions;
}

sf::FloatRect SpritedEntity::getSpriteGlobalBounds() const {
        return sprite.getGlobalBounds();
}

sf::FloatRect SpritedEntity::getSpriteLocalBounds() const {
        return sprite.getLocalBounds();
}
