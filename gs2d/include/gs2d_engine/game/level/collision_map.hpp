#ifndef GS_COLLISION_MAP_HPP
#define GS_COLLISION_MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "gs2d_engine/other/helpers/tile_grid.hpp"
#include "gs2d_engine/other/helpers/tile.hpp"
#include "gs2d_engine/scene/components/object/game_object.hpp"

namespace gs {

class CollisionMap {
private:
    bool loaded;
    TileGrid tile_grid;
    void handle_collision(GameObject &game_object, const sf::FloatRect &gb, const sf::FloatRect &tile_rect, const sf::Vector2f &movement);

public:
    CollisionMap();

    void load(const std::vector<int> &collision_layer_data,
              const sf::Vector2u &tile_size,
              const sf::Vector2u &level_size);

    void verify_collision(GameObject &game_object);
};

}

#endif
