#include "gs2d_engine/other/helpers/tile_grid.hpp"

namespace gs {

void TileGrid::check_boundaries(sf::Vector2i &before) {
        if (before.x < 0)
                before.x = 0;

        if (before.x > x_cells)
                before.x = x_cells;

        if (before.y < 0)
                before.y = 0;

        if (before.y > y_cells)
                before.y = y_cells;
}

TileGrid::TileGrid() {
}

TileGrid::TileGrid(sf::Vector2u tile_size, sf::Vector2u level_size, int unity_size)
        : GenericGrid::GenericGrid(level_size.x, level_size.y, unity_size) {
        this->tile_size = tile_size;
        unities.resize(x_cells * y_cells);
}

Unity *TileGrid::get_unity(int x, int y) {
        return &unities[x + y * x_cells];
}

void TileGrid::add_tile(Tile tile) {
        int tileX = tile.get_position_x();
        int tileY = tile.get_position_y();

        sf::Vector2i ul =
                sf::Vector2i((int)tileX / unity_size, (int)tileY / unity_size);
        sf::Vector2i ll =
                sf::Vector2i((int)tileX / unity_size, (int)(tileY + tile_size.y) / unity_size);
        sf::Vector2i ur =
                sf::Vector2i((int)(tileX + tile_size.x) / unity_size, (int)tileY / unity_size);
        sf::Vector2i lr = sf::Vector2i((int)(tileX + tile_size.x) / unity_size,
                                       (int)(tileY + tile_size.y) / unity_size);

        Unity *unity_ul = get_unity(ul.x, ul.y);
        Unity *unity_ll = get_unity(ll.x, ll.y);
        Unity *unity_ur = get_unity(ur.x, ur.y);
        Unity *unity_lr = get_unity(lr.x, lr.y);

        unity_ul->tiles.push_back(tile);

        if (unity_ll != unity_ul)
            unity_ll->tiles.push_back(tile);

        if (unity_ur != unity_ll && unity_ur != unity_ul)
            unity_ur->tiles.push_back(tile);

        if (unity_lr != unity_ur && unity_lr != unity_ll && unity_lr != unity_ul)
            unity_lr->tiles.push_back(tile);
}

std::vector<Unity>
TileGrid::get_unities_in_position(const sf::Vector2f &sprite_upper_left) {
        std::vector<Unity> adjacent;

        sf::Vector2i ul = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i ll = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)(sprite_upper_left.y + tile_size.y) / unity_size);
        sf::Vector2i ur = sf::Vector2i((int)(sprite_upper_left.x + tile_size.x) / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i lr = sf::Vector2i((int)(sprite_upper_left.x + tile_size.x) / unity_size,
                                       (int)(sprite_upper_left.y + tile_size.y) / unity_size);

        check_boundaries(ul);
        check_boundaries(ll);
        check_boundaries(ur);
        check_boundaries(lr);

        int upper_left = ul.x + ul.y * x_cells;
        int lower_left = ll.x + ll.y * x_cells;
        int upper_right = ur.x + ur.y * x_cells;
        int lower_right = lr.x + lr.y * x_cells;

        adjacent.push_back(upper_left >= (x_cells * y_cells)
                           ? unities[x_cells * y_cells - 1]
                           : unities[upper_left]);

        if (lower_left != upper_left) {
                adjacent.push_back(lower_left >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[lower_left]);
        }

        if (upper_right != lower_left && upper_right != upper_left) {
                adjacent.push_back(upper_right >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[upper_right]);
        }

        if (lower_right != upper_right && lower_right != lower_left &&
            lower_right != upper_left) {
                adjacent.push_back(lower_right >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[lower_right]);
        }

        return adjacent;
}

}
