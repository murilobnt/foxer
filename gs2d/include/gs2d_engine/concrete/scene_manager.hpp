// File: scene_manager.hpp
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
// IMPLIED, INCLUDING BUT Nget_game_heightOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <cstring>

#include "gs2d_engine/concrete/clock_handler.hpp"

// Forward declaration of the scene.

namespace gs {

class Scene;

// The scene manager will be responsible to delegate actions to
// its current scene. So, if a object that has a Scene Manager wants the
// scene to draw the entities, e.g., it will be needed to just call the
// scene manager to do so, and the scene manager will delegate it to the
// scene. If the scene is changed, the call to the scene manager will not
// change.

class SceneManager {

private:
	// The current scene. This will be the scene to be used on the
	// methods of this class.
	Scene* scene;

	// A pointer to the last scene. If it is the will of the coder
	// to create a return to the last scene (such as a pause menu to
	// return to the game), the information of the last scene can
	// be stored here.
	Scene* last_scene;

public:
	// Constructor.
	SceneManager();

	// Destructor.
	~SceneManager();

	// Change the scene to a new scene. Since the scene has a
	// pointer to the scene manager, the scene can change to another
	// one inside itself by calling this method.
	void change_scene(Scene* next_scene);

	// Change the scene to a new scene and store the last scene,
	// so it can be returned to the last one in the future.
	void change_to_runtime_scene(Scene* next_scene);

	// Delete the last scene.
	void remove_last_scene();

	// The following methods will repass the call for the current scene.
	void start();
	void update();
	void handle_event(sf::Event event, sf::RenderWindow& screen);
	void draw_entities(sf::RenderWindow& window);
	void reset_time_handlers(ClockHandler& clock_handler);

	// Setter for the scene. CAUTION: If you are changing from inside
	// a scene, it is recommended that you use change_scene, from
	// Scene, instead. Calling this method does not free the
	// pointer of the last scene, making it garbage in the execution.
	void set_scene(Scene* scene);

	// Setter for the last scene.
	void set_last_scene();

	// Getter for the scene.
	Scene* get_scene() const;

};

}

#endif
