#ifndef _TIMEHANDLER_HPP_
#define _TIMEHANDLER_HPP_

#include <SFML/Graphics.hpp>

class TimeHandler {
protected:
  sf::Time lastUpdate;
  sf::Time fps;

public:
  TimeHandler();
  TimeHandler(sf::Time fps);

  void restart(sf::Time elapsedTime);
  void resetLastUpdate();

  void setFps(sf::Time fps);
  bool timeToUpdate();
};

#endif
