#include "level_one_handler.hpp"

LevelOneHandler::LevelOneHandler() {}

LevelOneHandler::LevelOneHandler(
    const std::map<std::string, gs::TiledJsonObj> &events) {
  gs::TiledJsonObj m_exit = events.find("level_change")->second;
  exit = sf::FloatRect(m_exit.x, m_exit.y, m_exit.width, m_exit.height);
  destination_id = m_exit.properties["destination"].get<std::string>();
}

void LevelOneHandler::handle_event_collision(LevelManager *l_h,
                                             const sf::FloatRect &obj_rect) {
  if (exit.intersects(obj_rect)) {
    gs::TiledLevel level = gs::TiledLevel(
        std::vector<std::string>{"assets/tileset02.png",
                                 "assets/steampunkish-tilec.png"},
        "assets/level02.json");
    l_h->change_level(
        level,
        std::shared_ptr<LevelHandler>(new LevelOneHandler(level.get_events())),
        destination_id);
  }
}
