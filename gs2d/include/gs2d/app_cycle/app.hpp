// File: app.hpp
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

#ifndef GS_APP_HPP
#define GS_APP_HPP

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "gs2d/app_cycle/scene_proxy.hpp"
#include "gs2d/scene/scene.hpp"
#include "gs2d/time/clock_handler.hpp"
#include "gs2d/time/time_handler.hpp"

// The entity that maintains the application cycle. It is responsable for
// delegating actions for its scene managers, which repasses it
// to its current scene. It also keeps the application to the framerate.

namespace gs {

class App {

private:
  // The window of the application.
  sf::RenderWindow *app_window;

  // The title of the application window.
  std::string app_title;

  // The width and the height of the application window.
  int app_width;
  int app_height;

  float dt;

  // The clock of the application.
  ClockHandler clock_handler;

  // The timehandler to define the framerate of the application.
  TimeHandler app_frequency;

  // The scene proxy to delegate actions for the scene.
  SceneProxy scene_proxy;

  // This will process the events.
  void process_events();

  // This will clear the screen, draw and display the entities of
  // the current scene. It calls for the draw_entities method from the
  // scene.
  void clear_and_draw();

public:
  App();
  // Constructor. Requires the width and height of the application window and
  // its title too.
  App(int app_width, int app_height, std::string app_title,
      float framerate = 60.f);

  // Destructor.
  ~App();

  // Start the application. This begins the application cycle, verifying if the
  // window is still open to do the operations. It requires the first
  // scene to be played and the bool to use vsync.
  void app_start(Scene *first_scene, bool vsync = false);

  // Getters for the application width and height.
  int get_app_width() const;
  int get_app_height() const;
};

} // namespace gs

#endif
