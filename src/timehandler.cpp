#include "gamesimple/concrete/timehandler.hpp"

TimeHandler::TimeHandler() {
}

TimeHandler::TimeHandler(sf::Time fps) {
        lastUpdate = sf::Time::Zero;
        this->fps = fps;
}

void TimeHandler::restart(sf::Time elapsedTime) {
        lastUpdate += elapsedTime;
}

void TimeHandler::resetLastUpdate() {
        lastUpdate = sf::Time::Zero;
}

void TimeHandler::setFps(sf::Time fps) {
        lastUpdate = sf::seconds(fps.asSeconds() /
                                 (this->fps.asSeconds() /
                                  lastUpdate.asSeconds()));
        this->fps = fps;
}

bool TimeHandler::timeToUpdate() {
        if (lastUpdate > fps) {
                lastUpdate -= fps;
                return true;
        }

        return false;
}
