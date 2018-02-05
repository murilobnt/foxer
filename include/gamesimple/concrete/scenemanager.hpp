// File: scenemanager.hpp
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

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <cstring>

#include "gamesimple/concrete/clockhandler.hpp"

// Forward declaration of the scene.

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
	Scene* lastScene;

public:
	// Constructor.
	SceneManager();

	// Destructor.
	~SceneManager();

	// Change the scene to a new scene. Since the scene has a
	// pointer to the scene manager, the scene can change to another
	// one inside itself by calling this method.
	void changeScene(Scene* nextScene);

	// Change the scene to a new scene and store the last scene,
	// so it can be returned to the last one in the future.
	void changeToRuntimeScene(Scene* nextScene);

	// Delete the last scene.
	void removeLastScene();

	// The following methods will repass the call for the current scene.
	void start();
	void update();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);

	// Setter for the scene. CAUTION: If you are changing from inside
	// a scene, it is recommended that you use changeScene, from
	// Scene, instead. Calling this method does not free the
	// pointer of the last scene, making it garbage in the execution.
	void setScene(Scene* scene);

	// Setter for the last scene.
	void setLastScene();

	// Getter for the scene.
	Scene* getScene() const;
};

#endif
