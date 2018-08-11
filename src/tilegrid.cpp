#include "gamesimple/assist/tilegrid.hpp"

sf::Vector2i TileGrid::checkBoundaries(sf::Vector2i before) const {
        if (before.x < 0)
                before.x = 0;

        if (before.x > xCells)
                before.x = xCells;

        if (before.y < 0)
                before.y = 0;

        if (before.y > yCells)
                before.y = yCells;

        return before;
}

TileGrid::TileGrid() {
}

TileGrid::TileGrid(int w, int h, int unitySize)
        : GenericGrid::GenericGrid(w, h, unitySize) {
        unities.resize(xCells * yCells);
}

Unity *TileGrid::getUnity(int x, int y) {
        return &unities[x + y * xCells];
}

void TileGrid::addTile(Tile tile) {
        int tileX = tile.getPositionX();
        int tileY = tile.getPositionY();

        sf::Vector2i ul =
                sf::Vector2i((int)tileX / unitySize, (int)tileY / unitySize);
        sf::Vector2i ll =
                sf::Vector2i((int)tileX / unitySize, (int)(tileY + 32) / unitySize);
        sf::Vector2i ur =
                sf::Vector2i((int)(tileX + 32) / unitySize, (int)tileY / unitySize);
        sf::Vector2i lr = sf::Vector2i((int)(tileX + 32) / unitySize,
                                       (int)(tileY + 32) / unitySize);

        Unity *unityUl = getUnity(ul.x, ul.y);
        Unity *unityLl = getUnity(ll.x, ll.y);
        Unity *unityUr = getUnity(ur.x, ur.y);
        Unity *unityLr = getUnity(lr.x, lr.y);

        unityUl->tiles.push_back(tile);

        if (unityLl != unityUl)
                unityLl->tiles.push_back(tile);

        if (unityUr != unityLl && unityUr != unityUl)
                unityUr->tiles.push_back(tile);

        if (unityLr != unityUr && unityLr != unityLl && unityLr != unityUl)
                unityLr->tiles.push_back(tile);
}

std::vector<Unity>
TileGrid::getUnitiesOnPosition(sf::Vector2f spriteUpperLeft) const {
        std::vector<Unity> adjacent;

        sf::Vector2i ul = sf::Vector2i((int)spriteUpperLeft.x / unitySize,
                                       (int)spriteUpperLeft.y / unitySize);
        sf::Vector2i ll = sf::Vector2i((int)spriteUpperLeft.x / unitySize,
                                       (int)(spriteUpperLeft.y + 32) / unitySize);
        sf::Vector2i ur = sf::Vector2i((int)(spriteUpperLeft.x + 32) / unitySize,
                                       (int)spriteUpperLeft.y / unitySize);
        sf::Vector2i lr = sf::Vector2i((int)(spriteUpperLeft.x + 32) / unitySize,
                                       (int)(spriteUpperLeft.y + 32) / unitySize);

        ul = checkBoundaries(ul);
        ll = checkBoundaries(ll);
        ur = checkBoundaries(ur);
        lr = checkBoundaries(lr);

        int upperLeft = ul.x + ul.y * xCells;
        int lowerLeft = ll.x + ll.y * xCells;
        int upperRight = ur.x + ur.y * xCells;
        int lowerRight = lr.x + lr.y * xCells;

        adjacent.push_back(upperLeft >= (xCells * yCells)
                           ? unities[xCells * yCells - 1]
                           : unities[upperLeft]);

        if (lowerLeft != upperLeft) {
                adjacent.push_back(lowerLeft >= (xCells * yCells)
                                   ? unities[xCells * yCells - 1]
                                   : unities[lowerLeft]);
        }

        if (upperRight != lowerLeft && upperRight != upperLeft) {
                adjacent.push_back(upperRight >= (xCells * yCells)
                                   ? unities[xCells * yCells - 1]
                                   : unities[upperRight]);
        }

        if (lowerRight != upperRight && lowerRight != lowerLeft &&
            lowerRight != upperLeft) {
                adjacent.push_back(lowerRight >= (xCells * yCells)
                                   ? unities[xCells * yCells - 1]
                                   : unities[lowerRight]);
        }

        return adjacent;
}
