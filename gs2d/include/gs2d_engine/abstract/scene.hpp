// File: scene.hpp
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

#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

#include "gs2d_engine/concrete/clock_handler.hpp"
#include "gs2d_engine/concrete/scene_manager.hpp"
#include "gs2d_engine/concrete/texture_loader.hpp"
#include "gs2d_engine/concrete/time_handler.hpp"

// Scenes serves as the mold for any scene, e.g. the main menu
// and the pause screen. It contains methods for loading resources,
// updating the scene, event handling, entities drawing, timed actions
// events handling, time handlers reset, if necessary, and methods to
// define what the scene will do once it the user have exited it
// and once the user have resumed it.
// Every virtual method of this class is called by the game class
// which uses a scene manager to do the calls

namespace gs {

class Scene {

private:
    // The reference to the scene manager of the game. It is important for
    // the coder can change the current scene for another one inside the
    // scene.
    SceneManager *scene_manager;

protected:
    // The time handlers of the scene.
    std::vector<TimeHandler*> time_handlers;

public:
    // Virtual destructor. This means allocated memory with the new
    // operator can be freed on the child scene.
    virtual ~Scene();

    // Resources loading, like creating textures and setting sprites position.
    // If you're not implementing the method reset_time_handlers in the child,
    // I suggest to add every TimeHandler you may create to the vector time_handlers
    // of this class.
    virtual void start() = 0;

    // Updating phase. The method to implement this function will be called every
    // tick. e.g. a platform game where you constantly need to check if the player
    // have been hit by an enemy.
    virtual void update() = 0;

    // The method to implement this function will tell how an received event will
    // be handled. Using the EBControlableEntity class is recommended.
    virtual void handle_event(sf::Event event, sf::RenderWindow &screen) = 0;

    // Drawing phase. The method to implement this will be responsible
    // to draw every drawable entity of the scene.
    virtual void draw_entities(sf::RenderWindow &window) = 0;

    // This will define what will happen once the user have exited
    // the scene.
    virtual void on_exit();

    // This will change the current scene for another one.
    // The new scene is passed through the parameter, and it is
    // set into the scene manager, and used by the game.
    void change_scene(Scene *next_scene);

    // Reset all the time handlers used in the scene, in time_handlers vector
    // so they can be sycronized to the clock of the entire application.
    void reset_time_handlers(ClockHandler &clock_handler);

    // Will set a new scene manager to the scene.
    void set_scene_manager(SceneManager *scene_manager);

};

}

#endif
