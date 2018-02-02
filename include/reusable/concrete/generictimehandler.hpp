#ifndef _GENERICTIMEHANDLER_HPP_
#define _GENERICTIMEHANDLER_HPP_

#include <SFML/Graphics.hpp>

class GenericTimeHandler {
protected:
  sf::Time lastUpdate;
  sf::Time fps;

public:
  GenericTimeHandler();
  GenericTimeHandler(sf::Time fps);

  void restart(sf::Time elapsedTime);
  void resetLastUpdate();

  void setFps(sf::Time fps);
  bool timeToUpdate();
};

#endif
