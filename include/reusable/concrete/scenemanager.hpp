#ifndef _SCENEMANAGER_HPP_
#define _SCENEMANAGER_HPP_

#include <cstring>

#include "reusable/interface/texturemanager.hpp"
#include "reusable/concrete/clockhandler.hpp"
#include "reusable/enum/scenecatalog.hpp"

class Scene;

class SceneManager {
private:
	Scene* scene;
	Scene* lastScene;

	TextureManager* textureManager;

public:
	SceneManager();
	~SceneManager();

	void changeScene(SceneCatalog sceneCatalog);
	void changeToRuntimeScene(SceneCatalog sceneCatalog);
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
