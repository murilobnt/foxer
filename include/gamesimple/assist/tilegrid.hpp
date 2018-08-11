#ifndef TILEGRID_HPP
#define TILEGRID_HPP

// # External
#include <vector>
#include <cmath>

// # Internal
#include "gamesimple/assist/tile.hpp"
#include "gamesimple/assist/genericgrid.hpp"

struct Unity {

public:
    std::vector<Tile> tiles;

};

class TileGrid : public GenericGrid {

private:
    std::vector<Unity> unities;
    sf::Vector2i checkBoundaries(sf::Vector2i before) const;

public:
    TileGrid();

    TileGrid(int w, int h, int unity_size);

    Unity* getUnity(int x, int y);

    void addTile(Tile tile);

    std::vector<Unity> getUnitiesOnPosition(sf::Vector2f sprite_upper_left) const;

};

#endif
