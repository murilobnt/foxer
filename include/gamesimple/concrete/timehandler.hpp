// File: timehandler.hpp
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

#ifndef TIMEHANDLER_HPP
#define TIMEHANDLER_HPP

#include <SFML/Graphics.hpp>

// Time handler handles the time for an entity. It can be a member of
// the entity (recommended) or of the scene containing the entity.

class TimeHandler {

protected:
    // The time since the last update.
    sf::Time lastUpdate;

    // The framerate, in seconds.
    sf::Time fps;

public:
    // Constructor.
    TimeHandler();

    // Constructor. Sets the framerate.
    TimeHandler(sf::Time fps);

    // Restart the time handler with the elapsedTime. The elapsed time is
    // known by the ClockHandler, and it is recommended that the time handler
    // restarts any time handler
    //(by clockhandler.restartTimeHandler(TimeHandler*)).
    void restart(sf::Time elapsedTime);

    // Update the last update to the restart of the clock;
    void resetLastUpdate();

    void setFps(sf::Time fps);
    bool timeToUpdate();
    
};

#endif
