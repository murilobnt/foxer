#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include <cstring>

#include "gamesimple/interface/texturemanager.hpp"
#include "gamesimple/concrete/clockhandler.hpp"

class Scene;

class SceneManager {
private:
	Scene* scene;
	Scene* lastScene;

	TextureManager* textureManager;

public:
	SceneManager();
	~SceneManager();

	void changeScene(Scene* nextScene);
	void changeToRuntimeScene(Scene* nextScene);
	void removeLastScene();

	void start();
	void update();
	void handleEvent(sf::Event event, sf::RenderWindow& screen);
	void drawEntities(sf::RenderWindow& window);
	void doInternalTimedActions();
	void resetTimeHandlers(ClockHandler& clockHandler);

	void setScene(Scene* scene);
	void setLastScene();
	Scene* getScene() const;
};

#endif
