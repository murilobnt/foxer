#ifndef LEVEL_TWO_HANDLER_HPP
#define LEVEL_TWO_HANDLER_HPP

#include "level_handler.hpp"

class LevelTwoHandler : public LevelHandler {
public:
  void handle_event_collision(LevelManager *l_h, const sf::FloatRect &obj_rect);
};

#endif
