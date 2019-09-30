#include "foxer/time/clock_handler.hpp"

namespace fox {

ClockHandler::ClockHandler() {}

void ClockHandler::restart_clock() { elapsed_time = clock.restart(); }

void ClockHandler::restart_time_handler(TimeHandler *time_handler) {
  time_handler->restart(elapsed_time);
}

sf::Time ClockHandler::get_elapsed_time() const { return elapsed_time; }

} // namespace fox
