#include "gs2d_engine/game/level/collision_map.hpp"

namespace gs {

CollisionMap::CollisionMap() : loaded(false){

}

void CollisionMap::load(const std::vector<int> &collision_layer,
                        const sf::Vector2u &tile_size,
                        const sf::Vector2u &level_size){
    sf::Vector2u real_level_size(level_size.x * tile_size.x, level_size.y * tile_size.y);
    tile_grid = TileGrid(tile_size, real_level_size, 100);
    for (unsigned int i = 0; i < level_size.x; ++i)
        for (unsigned int j = 0; j < level_size.y; ++j) {
            int tile_number = collision_layer[i + j * level_size.x];
            --tile_number;

            if(tile_number == -1)
                continue;

            tile_grid.add_tile(Tile(sf::Vector2f(i * tile_size.x,
                                                 j * tile_size.y), tile_size));
        }
    loaded = true;
}

void CollisionMap::handle_collision(GameObject &game_object, sf::FloatRect& tile_rect){
    sf::FloatRect gb = game_object.get_sprite_global_bounds();
    sf::FloatRect copy = gb;
    sf::Vector2f movement = game_object.get_movement();

    bool col_y = false;
    bool col_x = false;

    copy.height -= 1;
    copy.width -= 1;
    copy.left += 0.5;
    copy.top += 0.5;
    copy.top += movement.y;
    if(tile_rect.intersects(copy)){
        game_object.set_movement_y(0);
        col_y = true;
    }
    copy = gb;

    copy.height -= 1;
    copy.width -= 1;
    copy.left += 0.5;
    copy.top += 0.5;
    copy.left += movement.x;
    if(tile_rect.intersects(copy)){
        game_object.set_movement_x(0);
        col_x = true;
    }
    copy = gb;

    if(col_x || col_y){
        float x = game_object.get_sprite_position().x;
        float y = game_object.get_sprite_position().y;

        if(col_y && !tile_rect.intersects(gb))
            y = tile_rect.top + ((gb.height) * (movement.y < 0 ? 1 : -1));
        if(col_x && !tile_rect.intersects(gb))
            x = tile_rect.left + ((gb.width) * (movement.x < 0 ? 1 : -1));
        game_object.set_sprite_position(x, y);
    }

}

void CollisionMap::verify_collision(GameObject &game_object){
    if(!loaded)
        return;

    sf::Vector2f movement = game_object.get_movement();
    sf::FloatRect gb = game_object.get_sprite_global_bounds();

    gb.left += movement.x;
    gb.top += movement.y;

    std::vector<Unity> unities = tile_grid.get_unities_in_position(game_object.get_sprite_position(), gb);

    for(std::vector<Unity>::iterator it = unities.begin(); it != unities.end(); ++it) {
    Unity unity = *it;

        for(std::vector<Tile>::iterator it2 = unity.tiles.begin(); it2 != unity.tiles.end(); ++it2) {
            sf::FloatRect tile_rect = (*it2).get_tile_rect();
            if(tile_rect.intersects(gb))
                handle_collision(game_object, tile_rect);
        }
    }
}

}
