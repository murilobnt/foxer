#include "gamesimple/assist/tile.hpp"

Tile::Tile(sf::Vector2f tilePosition, float tileWidth, float tileHeight){
        this->tilePosition = tilePosition;

        tileRect = sf::FloatRect(tilePosition,
                                 sf::Vector2f(tileWidth, tileHeight));
}

sf::Vector2f Tile::getPosition() const {
        return tilePosition;
}

float Tile::getPositionX() const {
        return tilePosition.x;
}

float Tile::getPositionY() const {
        return tilePosition.y;
}

sf::FloatRect Tile::getTileRect() const {
        return tileRect;
}
