#ifndef LEVEL_HANDLER_HPP
#define LEVEL_HANDLER_HPP

#include "level_manager.hpp"

class LevelHandler {
public:
  virtual void handle_event_collision(LevelManager *l_h,
                                      const sf::FloatRect &obj_rect) = 0;
};

#endif
