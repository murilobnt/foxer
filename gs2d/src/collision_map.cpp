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

    copy.top += movement.y;
    if(tile_rect.intersects(copy))
        game_object.set_movement_y(0);
    copy = gb;

    copy.left += movement.x;
    if(tile_rect.intersects(copy))
        game_object.set_movement_x(0);
    copy = gb;

}

void CollisionMap::verify_collision(GameObject &game_object){
    if(!loaded)
        return;

    sf::Vector2f movement = game_object.get_movement();    
    sf::FloatRect gb = game_object.get_sprite_global_bounds();

    gb.left += movement.x;
    gb.top += movement.y;

    std::vector<Unity> unities = tile_grid.get_unities_in_position(game_object.get_sprite_position());

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
