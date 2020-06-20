// File: scene.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
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

#ifndef FOX_SCENE_HPP_
#define FOX_SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "foxer/logical/level_bundle.hpp"
#include "foxer/logical/local_texture_repository.hpp"
#include "foxer/logical/scene_builder.hpp"
#include "foxer/logical/shared_texture_repository.hpp"
#include "foxer/logical/texture_loader.hpp"
#include "foxer/time.hpp"

// Scenes serves as the mold for any scene, e.g. the main menu
// and the pause screen. It contains methods for loading resources,
// updating the scene, event handling, entities drawing, timed actions
// events handling, time handlers reset, if necessary, and methods to
// define what the scene will do once it the user have exited it
// and once the user have resumed it.
// Every virtual method of this class is called by the game class
// which uses a scene manager to do the calls

namespace fox {

class Scene {
public:
  Scene();

  // Virtual destructor. This means allocated memory with the new
  // operator can be freed on the child scene.
  virtual ~Scene();

  // Resources loading, like creating textures and setting sprites position.
  // If you're not implementing the method reset_time_handlers in the child,
  // I suggest to add every TimeHandler you may create to the vector
  // time_handlers of this class.
  virtual void start() = 0;

  // Updating phase. The method to implement this function will be called every
  // tick. e.g. a platform game where you constantly need to check if the player
  // have been hit by an enemy.
  virtual void update() = 0;

  // The method to implement this function will tell how an received event will
  // be handled. Using the EBControlableEntity class is recommended.
  virtual void handle_event(sf::Event &event);

  // Drawing phase. The method to implement this will be responsible
  // to draw every drawable entity of the scene.
  virtual void draw_entities() = 0;

  // This will define what will happen once the user have exited
  // the scene.
  virtual void on_exit();

  // This will change the current scene for another one.
  // The new scene is passed through the parameter, and it is
  // set into the scene manager, and used by the game.
  void push_scene(Scene *next_scene);

  void rollback_scene();

  // Reset all the time handlers used in the scene, in time_handlers vector
  // so they can be sycronized to the clock of the entire application.
  void reset_time_handlers(ClockHandler &clock_handler);

  // Setter of app_window.
  void set_app_window(sf::RenderWindow *app_window);

  void set_app_clock(ClockHandler *app_clock);

  float get_frame_delta_time() const;

  void set_app_state(std::vector<std::shared_ptr<Scene>> *app_state);

protected:
  // The time handlers of the scene.
  std::vector<TimeHandler *> time_handlers;

  // The window of the application.
  sf::RenderWindow *app_window;
  LocalTextureRepository ltex_repo;
  SharedTextureRepository stex_repo;

private:
  ClockHandler *app_clock;
  std::vector<std::shared_ptr<Scene>> *app_state;
};

} // namespace fox

#endif
