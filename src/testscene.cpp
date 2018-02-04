#include "instance/testscene.hpp"

TestScene::TestScene(SceneManager *sceneManager) : Scene::Scene(sceneManager) {}

void TestScene::start() {
  textureLoader.setTextureFromFile(
      this->charTexture, std::string("images/linkEdit.png"), 1200, 1040);
  character = Character(this->charTexture, 0, 0, 120, 130, 0, 1200, 520, 910, 20);
  character.setSpriteScale(0.4, 0.4);

  textureLoader.setTextureFromFile(
      this->bgTexture, std::string("images/7536921_orig.png"), 1000, 750);
  bg = SpritedEntity(this->bgTexture, 0, 0, 1000, 750);

  character.setSpritePosition(sf::Vector2f(0, 0));
  bg.setSpritePosition(sf::Vector2f(0, 0));
}

void TestScene::update() { character.moveCharacter(); }

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
  window.draw(bg.getSprite());
  window.draw(character.getSprite());
}

void TestScene::doInternalTimedActions() {
  while (character.getAnimationTimeHandler().timeToUpdate())
    character.animate();
}

void TestScene::resetTimeHandlers(ClockHandler &clockHandler) {
    clockHandler.restartTimeHandler(&character.getAnimationTimeHandler());
}

void TestScene::onExit() {}

void TestScene::resumeScene() {}
