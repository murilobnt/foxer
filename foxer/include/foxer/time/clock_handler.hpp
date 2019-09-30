// File: clock_handler.hpp
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
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_CLOCK_HANDLER_HPP
#define FOX_CLOCK_HANDLER_HPP

#include "foxer/time/time_handler.hpp"

// Handles the clock of the game. It serves to make the game only
// have a single clock, which every entity can use to syncronize their
// time handlers.

namespace fox {

class ClockHandler {

private:
  // The SFML clock.
  sf::Clock clock;

  // The elapsed time of the clock.
  sf::Time elapsed_time;

public:
  // Constructor.
  ClockHandler();

  // Restart the clock and register the elapsed time.
  void restart_clock();

  // Restart the given time handler to the clock's elapsed time.
  void restart_time_handler(TimeHandler *time_handler);

  // Getters.
  sf::Time get_elapsed_time() const;
};

} // namespace fox

#endif
