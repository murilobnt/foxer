#include "gs2d_engine/assist/tile_grid.hpp"

sf::Vector2i TileGrid::checkBoundaries(sf::Vector2i before) const {
        if (before.x < 0)
                before.x = 0;

        if (before.x > x_cells)
                before.x = x_cells;

        if (before.y < 0)
                before.y = 0;

        if (before.y > y_cells)
                before.y = y_cells;

        return before;
}

TileGrid::TileGrid() {
}

TileGrid::TileGrid(int w, int h, int unity_size)
        : GenericGrid::GenericGrid(w, h, unity_size) {
        unities.resize(x_cells * y_cells);
}

Unity *TileGrid::getUnity(int x, int y) {
        return &unities[x + y * x_cells];
}

void TileGrid::addTile(Tile tile) {
        int tileX = tile.get_position_x();
        int tileY = tile.get_position_y();

        sf::Vector2i ul =
                sf::Vector2i((int)tileX / unity_size, (int)tileY / unity_size);
        sf::Vector2i ll =
                sf::Vector2i((int)tileX / unity_size, (int)(tileY + 32) / unity_size);
        sf::Vector2i ur =
                sf::Vector2i((int)(tileX + 32) / unity_size, (int)tileY / unity_size);
        sf::Vector2i lr = sf::Vector2i((int)(tileX + 32) / unity_size,
                                       (int)(tileY + 32) / unity_size);

        Unity *unity_ul = getUnity(ul.x, ul.y);
        Unity *unity_ll = getUnity(ll.x, ll.y);
        Unity *unity_ur = getUnity(ur.x, ur.y);
        Unity *unity_lr = getUnity(lr.x, lr.y);

        unity_ul->tiles.push_back(tile);

        if (unity_ll != unity_ul)
                unity_ll->tiles.push_back(tile);

        if (unity_ur != unity_ll && unity_ur != unity_ul)
                unity_ur->tiles.push_back(tile);

        if (unity_lr != unity_ur && unity_lr != unity_ll && unity_lr != unity_ul)
                unity_lr->tiles.push_back(tile);
}

std::vector<Unity>
TileGrid::getUnitiesOnPosition(sf::Vector2f sprite_upper_left) const {
        std::vector<Unity> adjacent;

        sf::Vector2i ul = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i ll = sf::Vector2i((int)sprite_upper_left.x / unity_size,
                                       (int)(sprite_upper_left.y + 32) / unity_size);
        sf::Vector2i ur = sf::Vector2i((int)(sprite_upper_left.x + 32) / unity_size,
                                       (int)sprite_upper_left.y / unity_size);
        sf::Vector2i lr = sf::Vector2i((int)(sprite_upper_left.x + 32) / unity_size,
                                       (int)(sprite_upper_left.y + 32) / unity_size);

        ul = checkBoundaries(ul);
        ll = checkBoundaries(ll);
        ur = checkBoundaries(ur);
        lr = checkBoundaries(lr);

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
