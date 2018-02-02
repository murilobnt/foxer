#include "instance/testscene.hpp"

TestScene::TestScene(SceneManager *sceneManager) : Scene::Scene(sceneManager) {}

void TestScene::start() {
  shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color::Green);
}

void TestScene::update() {}

void TestScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    switch (event.key.code) {
    case sf::Keyboard::X:
      std::cout << "You've pressed X!" << std::endl;
      break;
    }
    break;
  }
}

void TestScene::drawEntities(sf::RenderWindow &window) { window.draw(shape); }

void TestScene::doInternalTimedActions() {}

void TestScene::resetTimeHandlers(ClockHandler &clockHandler) {}

void TestScene::onExit() {}

void TestScene::resumeScene() {}
