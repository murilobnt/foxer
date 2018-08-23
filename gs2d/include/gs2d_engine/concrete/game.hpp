// File: game.hpp
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

#ifndef GS_GAME_HPP
#define GS_GAME_HPP

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "gs2d_engine/concrete/clock_handler.hpp"
#include "gs2d_engine/concrete/time_handler.hpp"
#include "gs2d_engine/concrete/scene_manager.hpp"
#include "gs2d_engine/abstract/scene.hpp"

// The entity that maintains the game cycle. It is responsable for
// delegating actions for its scene managers, which repasses it
// to its current scene. It also keeps the game to the framerate.

namespace gs {

class Game {

private:
    // The window of the application.
    sf::RenderWindow *app_window;

    // The title of the game window.
    std::string game_title;

    // The width and the height of the game window.
    int game_width;
    int game_height;

    // The clock of the game.
    ClockHandler clock_handler;

    // The timehandler to define the framerate of the game.
    TimeHandler game_frequency;

    // The scene manager to delegate actions for the scene.
    SceneManager scene_manager;

    // This will handle the actions inside the framerate.
    void handle_time_actions();

    // This will process the events.
    void process_events();

    // This will clear the screen, draw and display the entities of
    // the current scene. It calls for the draw_entities method from the
    // scene.
    void clear_and_draw();

public:
    Game();
    // Constructor. Requires the width and height of the game window and its
    // title too.
    Game(int game_width, int game_height, std::string game_title, float framerate = 60.f);

    // Destructor.
    ~Game();

    // Start the game. This begins the game cycle, verifying if the
    // window is still open to do the operations. It requires the first
    // scene to be played and the bool to use vsync.
    void game_start(Scene* first_scene, bool vsync = true);

    // Getters for the game width and height.
    int get_game_width() const;
    int get_game_height() const;
};

}

#endif
