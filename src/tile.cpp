#include "gamesimple/assist/tile.hpp"

Tile::Tile(sf::Vector2f tile_position, float tile_width, float tile_height){
        this->tile_position = tile_position;

        tile_rect = sf::FloatRect(tile_position,
                                 sf::Vector2f(tile_width, tile_height));
}

sf::Vector2f Tile::get_position() const {
        return tile_position;
}

float Tile::get_position_x() const {
        return tile_position.x;
}

float Tile::get_position_y() const {
        return tile_position.y;
}

sf::FloatRect Tile::get_tile_rect() const {
        return tile_rect;
}
