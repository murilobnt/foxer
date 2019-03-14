#include "gs2d/time/time_handler.hpp"

namespace gs {

TimeHandler::TimeHandler() {}

TimeHandler::TimeHandler(sf::Time update_rate) {
  last_update = sf::Time::Zero;
  this->update_rate = update_rate;
}

void TimeHandler::restart(sf::Time elapsed_time) {
  last_update += elapsed_time;
}

void TimeHandler::reset_last_update() { last_update = sf::Time::Zero; }

void TimeHandler::set_update_rate(sf::Time update_rate) {
  last_update =
      sf::seconds(update_rate.asSeconds() /
                  (this->update_rate.asSeconds() / last_update.asSeconds()));
  this->update_rate = update_rate;
}

bool TimeHandler::time_to_update() {
  if (last_update > update_rate) {
    last_update -= update_rate;
    return true;
  }

  return false;
}

sf::Time TimeHandler::get_last_update() const { return last_update; }

sf::Time TimeHandler::get_update_rate() const { return update_rate; }

} // namespace gs
