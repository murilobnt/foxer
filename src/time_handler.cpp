#include "gs2d_engine/concrete/time_handler.hpp"

TimeHandler::TimeHandler() {
}

TimeHandler::TimeHandler(sf::Time fps) {
        last_update = sf::Time::Zero;
        this->fps = fps;
}

void TimeHandler::restart(sf::Time elapsed_time) {
        last_update += elapsed_time;
}

void TimeHandler::reset_last_update() {
        last_update = sf::Time::Zero;
}

void TimeHandler::set_fps(sf::Time fps) {
        last_update = sf::seconds(fps.asSeconds() /
                                 (this->fps.asSeconds() /
                                  last_update.asSeconds()));
        this->fps = fps;
}

bool TimeHandler::time_to_update() {
        if (last_update > fps) {
                last_update -= fps;
                return true;
        }

        return false;
}
