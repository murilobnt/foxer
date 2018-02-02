#include "gamesimple/concrete/timehandler.hpp"

TimeHandler::TimeHandler() {}

TimeHandler::TimeHandler(sf::Time fps) {
  this->lastUpdate = sf::Time::Zero;
  this->fps = fps;
}

void TimeHandler::restart(sf::Time elapsedTime) {
  this->lastUpdate += elapsedTime;
}

void TimeHandler::resetLastUpdate() {
  this->lastUpdate = sf::Time::Zero;
}

void TimeHandler::setFps(sf::Time fps) {
  this->lastUpdate = sf::seconds(
      fps.asSeconds() / (this->fps.asSeconds() / lastUpdate.asSeconds()));
  this->fps = fps;
}

bool TimeHandler::timeToUpdate() {
  if (this->lastUpdate > this->fps) {
    this->lastUpdate -= this->fps;
    return true;
  }
  return false;
}
