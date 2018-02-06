#include "gamesimple/assist/tile.hpp"

Tile::Tile(sf::Vector2f tilePosition, float tileWidth, float tileHeight){
  this->tilePosition = tilePosition;
  tileRect = sf::FloatRect(tilePosition, sf::Vector2f(tileWidth, tileHeight));
}

sf::Vector2f Tile::getPosition() const{
  return this->tilePosition;
}

float Tile::getPositionX() const{
  return this->tilePosition.x;
}

float Tile::getPositionY() const{
  return this->tilePosition.y;
}

sf::FloatRect Tile::getTileRect() const{
  return this->tileRect;
}
