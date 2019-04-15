#include "gs2d/game/level/level.hpp"
#include "gs2d/game/level/level_proxy.hpp"

namespace gs {

LevelProxy::LevelProxy() {}

void LevelProxy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(*current_level);
}

LevelProxy::LevelProxy(Level *first_level) {
  current_level = std::shared_ptr<Level>(first_level);
}

void LevelProxy::change_level(Level *next_level) {
  current_level = std::shared_ptr<Level>(next_level);
  current_level->init();
}

void LevelProxy::change_level(std::shared_ptr<Level> next_level) {
  current_level = next_level;
  current_level->init();
}

void LevelProxy::handle_events() { current_level->handle_events(); }

} // namespace gs
