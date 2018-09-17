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

        sf::Vector2i center = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i up = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)(sprite_upper_left.y - tile_size.y) / unity_size);
        sf::Vector2i down = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)(sprite_upper_left.y + tile_size.y * 2) / unity_size);
        sf::Vector2i right = sf::Vector2i((int)(sprite_upper_left.x + tile_size.x * 2) / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i left = sf::Vector2i((int)(sprite_upper_left.x - tile_size.x) / unity_size,
                                       (int)(sprite_upper_left.y) / unity_size);

       sf::Vector2i up_left = sf::Vector2i((int)(sprite_upper_left.x - tile_size.x) / unity_size,
                                      (int)(sprite_upper_left.y - tile_size.y) / unity_size);
       sf::Vector2i up_right = sf::Vector2i((int)(sprite_upper_left.x + tile_size.x * 2) / unity_size,
                                      (int)(sprite_upper_left.y - tile_size.y) / unity_size);
       sf::Vector2i down_left = sf::Vector2i((int)(sprite_upper_left.x - tile_size.x) / unity_size,
                                      (int)(sprite_upper_left.y + tile_size.y * 2) / unity_size);
       sf::Vector2i down_right = sf::Vector2i((int)(sprite_upper_left.x + tile_size.x * 2) / unity_size,
                                      (int)(sprite_upper_left.y + tile_size.y * 2) / unity_size);

        check_boundaries(center);
        check_boundaries(up);
        check_boundaries(down);
        check_boundaries(right);
        check_boundaries(left);
        check_boundaries(up_left);
        check_boundaries(up_right);
        check_boundaries(down_left);
        check_boundaries(down_right);

        int at_center = center.x + center.y * x_cells;
        int above = up.x + up.y * x_cells;
        int below = down.x + down.y * x_cells;
        int at_right = right.x + right.y * x_cells;
        int at_left = left.x + left.y * x_cells;
        int ul = up_left.x + up_left.y * x_cells;
        int ur = up_right.x + up_right.y * x_cells;
        int dl = down_left.x + down_left.y * x_cells;
        int dr = down_right.x + down_right.y * x_cells;

        adjacent.push_back(at_center >= (x_cells * y_cells)
                           ? unities[x_cells * y_cells - 1]
                           : unities[at_center]);

        if(above != at_center)
        adjacent.push_back(above >= (x_cells * y_cells)
                           ? unities[x_cells * y_cells - 1]
                           : unities[above]);

        if (below != above && below != at_center) {
                adjacent.push_back(below >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[below]);
        }

        if (at_right != below && at_right != above && at_right != at_center) {
                adjacent.push_back(at_right >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[at_right]);
        }

        if (at_left != at_right && at_left != below &&
            at_left != above && at_left != at_center) {
                adjacent.push_back(at_left >= (x_cells * y_cells)
                                   ? unities[x_cells * y_cells - 1]
                                   : unities[at_left]);
        }

        if(ul != at_left && ul != at_right && ul != below &&
            ul != above && ul != at_center)
            adjacent.push_back(at_left >= (x_cells * y_cells)
                               ? unities[x_cells * y_cells - 1]
                               : unities[ul]);

       if(ur != ul && ur != at_left && ur != at_right && ur != below &&
           ur != above && ur != at_center)
           adjacent.push_back(at_left >= (x_cells * y_cells)
                              ? unities[x_cells * y_cells - 1]
                              : unities[ur]);

        if(dl != ur && dl != ul && dl != at_left && dl != at_right && dl != below &&
            dl != above && dl != at_center)
            adjacent.push_back(at_left >= (x_cells * y_cells)
                               ? unities[x_cells * y_cells - 1]
                               : unities[dl]);

        if(dr != dl && dr != ur && dr != ul && dr != at_left && dr != at_right && dr != below &&
            dr != above && dr != at_center)
            adjacent.push_back(at_left >= (x_cells * y_cells)
                               ? unities[x_cells * y_cells - 1]
                               : unities[dr]);

        return adjacent;
}

}
