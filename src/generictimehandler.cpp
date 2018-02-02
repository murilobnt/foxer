#include "reusable/concrete/generictimehandler.hpp"

GenericTimeHandler::GenericTimeHandler() {}

GenericTimeHandler::GenericTimeHandler(sf::Time fps) {
  this->lastUpdate = sf::Time::Zero;
  this->fps = fps;
}

void GenericTimeHandler::restart(sf::Time elapsedTime) {
  this->lastUpdate += elapsedTime;
}

void GenericTimeHandler::resetLastUpdate() {
  this->lastUpdate = sf::Time::Zero;
}

void GenericTimeHandler::setFps(sf::Time fps) {
  this->lastUpdate = sf::seconds(
      fps.asSeconds() / (this->fps.asSeconds() / lastUpdate.asSeconds()));
  this->fps = fps;
}

bool GenericTimeHandler::timeToUpdate() {
  if (this->lastUpdate > this->fps) {
    this->lastUpdate -= this->fps;
    return true;
  }
  return false;
}
