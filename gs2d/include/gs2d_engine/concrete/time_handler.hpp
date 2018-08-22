// File: time_handler.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef TIME_HANDLER_HPP
#define TIME_HANDLER_HPP

#include <SFML/Graphics.hpp>

// Time handler handles the time for an entity. It can be a member of
// the entity (recommended) or of the scene containing the entity.

class TimeHandler {

private:
    // The time since the last update.
    sf::Time last_update;

    // The framerate, in seconds.
    sf::Time update_rate;

public:
    // Constructor.
    TimeHandler();

    // Constructor. Sets the update rate.
    TimeHandler(sf::Time update_rate);

    // Restart the time handler with the elapsed_time. The elapsed time is
    // known by the ClockHandler, and it is recommended that the time handler
    // restarts any time handler
    //(by clockhandler.restart_time_handler(TimeHandler*)).
    void restart(sf::Time elapsed_time);

    // Update the last update to the restart of the clock.
    void reset_last_update();

    // Setter for update_rate.
    void set_update_rate(sf::Time update_rate);

    // Returns true if it's time to update something. False otherwise.
    // By update, it's meant the time space of update_rate after
    // the last_update.
    bool time_to_update();

};

#endif
