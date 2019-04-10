#ifndef LEVEL_ONE_HANDLER_HPP
#define LEVEL_ONE_HANDLER_HPP

#include <map>

#include "level_handler.hpp"

class LevelOneHandler : public LevelHandler {
private:
  sf::FloatRect exit;
  std::string destination_id;

public:
  LevelOneHandler();
  LevelOneHandler(const std::map<std::string, gs::TiledJsonObj> &events);
  void handle_event_collision(LevelManager *l_h, const sf::FloatRect &obj_rect);
};

#endif
