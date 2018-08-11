#include "gamesimple/concrete/clockhandler.hpp"

ClockHandler::ClockHandler() {
}

void ClockHandler::restart_clock() {
        elapsed_time = clock.restart();
}

void ClockHandler::restart_time_handler(TimeHandler *time_handler) {
        time_handler->restart(elapsed_time);
}
