#ifndef _CLOCKHANDLER_HPP_
#define _CLOCKHANDLER_HPP_

#include "gamesimple/concrete/timehandler.hpp"

class ClockHandler {
private:
  sf::Clock clock;
  sf::Time elapsedTime;

public:
  ClockHandler();

  void restartClock();
  void restartTimeHandler(TimeHandler *genericTimeHandler);
};

#endif
