#include "gamesimple/concrete/clockhandler.hpp"

ClockHandler::ClockHandler() {
}

void ClockHandler::restartClock() {
        elapsedTime = clock.restart();
}

void ClockHandler::restartTimeHandler(TimeHandler *genericTimeHandler) {
        genericTimeHandler->restart(elapsedTime);
}
