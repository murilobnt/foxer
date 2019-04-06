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

  for (int i = 0; i < tilesets.size(); ++i) {
    std::shared_ptr<sf::Texture> texture(new sf::Texture);
    texture->loadFromFile(tilesets[i]);

    std::shared_ptr<sf::VertexArray> m_v(new sf::VertexArray);
    m_v->setPrimitiveType(sf::Quads);
    m_v->resize(level_size.x * level_size.y * 4);

    m_data.push_back(std::pair<std::shared_ptr<sf::Texture>,
                               std::shared_ptr<sf::VertexArray>>(texture, m_v));
  }

  for (unsigned int i = 0; i < level_size.x; ++i)
    for (unsigned int j = 0; j < level_size.y; ++j) {
      int tile_number = tiles[i + j * level_size.x];

      if (tile_number == 0)
        continue;

      std::pair<std::shared_ptr<sf::Texture>, std::shared_ptr<sf::VertexArray>>
          current;
      int acumulator = 0;

      for (int i = 0; i < m_data.size(); ++i) {
        current = m_data[i];
        sf::Vector2u size = current.first->getSize();
        int tiles_in_tex = (size.x / tile_size.x) * (size.y / tile_size.y);

        if (tile_number <= acumulator + tiles_in_tex)
          break;

        acumulator += tiles_in_tex;
      }

      tile_number -= acumulator;
      --tile_number;

      int tu = tile_number % (current.first->getSize().x / tile_size.x);
      int tv = tile_number / (current.first->getSize().x / tile_size.x);

      if (tu != -1 || tv != -1) {
        std::shared_ptr<sf::VertexArray> bleh = current.second;
        sf::Vertex *quad = &(*bleh)[(i + j * level_size.x) * 4];

        quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
        quad[1].position = sf::Vector2f((i + 1) * tile_size.x, j * tile_size.y);
        quad[2].position =
            sf::Vector2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
        quad[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y);

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
  states.transform *= getTransform();

  for (int i = 0; i < m_data.size(); ++i) {
    std::pair<std::shared_ptr<sf::Texture>, std::shared_ptr<sf::VertexArray>>
        context = m_data[i];
    states.texture = context.first.get();
    target.draw(*context.second, states);
  }
}

} // namespace gs
