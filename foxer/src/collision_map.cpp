#include "foxer/game/level/collision_map.hpp"

namespace fox {

CollisionMap::CollisionMap() : loaded(false) {}

void CollisionMap::load(const std::vector<int> &collision_layer,
                        const sf::Vector2u &tile_size,
                        const sf::Vector2u &level_size) {
  sf::Vector2u real_level_size(level_size.x * tile_size.x,
                               level_size.y * tile_size.y);
  tile_grid = TileGrid(tile_size, real_level_size, tile_size.x * 6);
  for (unsigned int i = 0; i < level_size.x; ++i)
    for (unsigned int j = 0; j < level_size.y; ++j) {
      int tile_number = collision_layer[i + j * level_size.x];
      --tile_number;

      if (tile_number == -1)
        continue;

      tile_grid.add_tile(
          Tile(sf::Vector2f(i * tile_size.x, j * tile_size.y), tile_size));
    }
  loaded = true;
}

void CollisionMap::handle_collision(GameObject &game_object,
                                    const sf::FloatRect &gb,
                                    const sf::FloatRect &tile_rect,
                                    const sf::Vector2f &movement) {
  sf::FloatRect copy = gb;

  float l_offset_y =
      (tile_rect.top > gb.top ? game_object.collision_offset_up
                              : game_object.collision_offset_down);
  float l_offset_x =
      (tile_rect.left > gb.left ? game_object.collision_offset_left
                                : game_object.collision_offset_right);

  copy.height -= l_offset_y;
  copy.width -= l_offset_x;
  copy.left += l_offset_x / 2;
  copy.top += l_offset_y / 2;
  copy.top += movement.y;
  if (tile_rect.intersects(copy))
    game_object.set_movement_y(0);
  copy = gb;

  copy.height -= l_offset_y;
  copy.width -= l_offset_x;
  copy.left += l_offset_x / 2;
  copy.top += l_offset_y / 2;
  copy.left += movement.x;
  if (tile_rect.intersects(copy))
    game_object.set_movement_x(0);
}

void CollisionMap::verify_collision(GameObject &game_object) {
  if (!loaded)
    return;

  sf::Vector2f movement = game_object.get_movement();
  sf::FloatRect gb = game_object.get_sprite_global_bounds();

  gb.left += movement.x;
  gb.top += movement.y;

  std::vector<Unity> unities =
      tile_grid.get_unities_in_position(game_object.get_sprite_position(), gb);

  for (std::vector<Unity>::iterator it = unities.begin(); it != unities.end();
       ++it) {
    Unity unity = *it;

    for (std::vector<Tile>::iterator it2 = unity.tiles.begin();
         it2 != unity.tiles.end(); ++it2) {
      sf::FloatRect tile_rect = (*it2).get_tile_rect();
      if (tile_rect.intersects(gb))
        handle_collision(game_object, game_object.get_sprite_global_bounds(),
                         tile_rect, movement);
    }
  }
}

} // namespace fox
