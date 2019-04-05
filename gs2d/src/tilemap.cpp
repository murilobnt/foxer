#include "gs2d/game/level/tilemap.hpp"

namespace gs {

TileMap::TileMap() {}

TileMap::TileMap(const std::vector<std::string> &tilesets,
                 const sf::Vector2u &tile_size, const sf::Vector2u &level_size,
                 const std::vector<int> &tiles) {
  load(tilesets, tile_size, level_size, tiles);
}

bool TileMap::load(const std::vector<std::string> &tilesets,
                   const sf::Vector2u &tile_size,
                   const sf::Vector2u &level_size,
                   const std::vector<int> &tiles) {
  // load the tileset texture

  for (int i = 0; i < tilesets.size(); ++i) {
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile(tilesets[i]);

    sf::VertexArray *m_v = new sf::VertexArray;
    m_v->setPrimitiveType(sf::Quads);
    m_v->resize(level_size.x * level_size.y * 4);

    m_data.push_back(std::pair<sf::Texture *, sf::VertexArray *>(texture, m_v));
  }

  // populate the vertex array, with one quad per tile
  for (unsigned int i = 0; i < level_size.x; ++i)
    for (unsigned int j = 0; j < level_size.y; ++j) {
      // get the current tile number
      int tile_number = tiles[i + j * level_size.x];

      if (tile_number == 0)
        continue;

      std::pair<sf::Texture *, sf::VertexArray *> current;
      int acumulator = 0;

      for (int i = 0; i < m_data.size(); ++i) {
        current = m_data[i];
        sf::Vector2u size = current.first->getSize();
        spr.setTexture(*current.first);
        int tiles_in_tex = (size.x / tile_size.x) * (size.y / tile_size.y);

        if (tile_number < acumulator + tiles_in_tex)
          break;

        acumulator += tiles_in_tex;
      }

      tile_number -= acumulator;
      --tile_number;

      // find its position in the tileset texture
      int tu = tile_number % (current.first->getSize().x / tile_size.x);
      int tv = tile_number / (current.first->getSize().x / tile_size.x);

      if (tu != -1 || tv != -1) {
        // get a pointer to the current tile's quad
        sf::VertexArray *bleh = current.second;
        sf::Vertex *quad = &(*bleh)[(i + j * level_size.x) * 4];

        // define its 4 corners
        quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
        quad[1].position = sf::Vector2f((i + 1) * tile_size.x, j * tile_size.y);
        quad[2].position =
            sf::Vector2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
        quad[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y);

        // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * tile_size.x, tv * tile_size.y);
        quad[1].texCoords =
            sf::Vector2f((tu + 1) * tile_size.x, tv * tile_size.y);
        quad[2].texCoords =
            sf::Vector2f((tu + 1) * tile_size.x, (tv + 1) * tile_size.y);
        quad[3].texCoords =
            sf::Vector2f(tu * tile_size.x, (tv + 1) * tile_size.y);
      }
    }
  return true;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  // apply the transform
  states.transform *= getTransform();

  for (int i = 0; i < m_data.size(); ++i) {
    std::pair<sf::Texture *, sf::VertexArray *> context = m_data[i];
    states.texture = context.first;
    target.draw(*context.second, states);
  }
}

} // namespace gs
