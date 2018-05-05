#include "instance/secondscene.hpp"

SecondScene::SecondScene(SceneManager *sceneManager)
    : Scene::Scene(sceneManager) {}

SecondScene::SecondScene() : Scene::Scene() {}

void SecondScene::start() {
  shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color::Green);
}

void SecondScene::update() {}

void SecondScene::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  switch (event.type) {
  case sf::Event::KeyReleased:
    switch (event.key.code) {
    case sf::Keyboard::Return:
      changeScene(new SecondScene(this->sceneManager));
      break;
    }
    break;
  }
}

void SecondScene::drawEntities(sf::RenderWindow &window) { window.draw(shape); }

void SecondScene::resetTimeHandlers(ClockHandler &clockHandler) {}
void SecondScene::onExit() {}
void SecondScene::resumeScene() {}
