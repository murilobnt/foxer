#include "instance/testscene.hpp"

TestScene::TestScene(SceneManager *sceneManager, TextureLoader &textureLoader)
    : Scene::Scene(sceneManager, textureLoader),
      character(textureLoader.getTexture(), 0, 0, 0, 32, 0, 32) {}

TestScene::TestScene(SceneManager *sceneManager, std::string pathToImage, int w,
                     int h, bool isRepeated, bool hasBitmask)
    : Scene::Scene(sceneManager, pathToImage, w, h, isRepeated, hasBitmask),
      character(textureLoader.getTexture(), 0, 0, 0, 32, 0, 32) {}

void TestScene::start() {
  shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color::Green);
  character.setSpritePosition(sf::Vector2f(0, 0));
}

void TestScene::update() {}

void TestScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    character.controlEntity(event.key.code, true);
    break;
  case sf::Event::KeyPressed:
    character.controlEntity(event.key.code, false);
    break;
  }
}

void TestScene::drawEntities(sf::RenderWindow &window) {
  window.draw(shape);
  window.draw(character.getSprite());
}

void TestScene::doInternalTimedActions() {}

void TestScene::resetTimeHandlers(ClockHandler &clockHandler) {}

void TestScene::onExit() {}

void TestScene::resumeScene() {}
