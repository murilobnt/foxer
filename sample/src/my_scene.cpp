#include "my_scene.hpp"

void MyScene::start() {
  circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Green);
}

void MyScene::update() {
  // we'll do nothing over here
}

void MyScene::draw_entities() { app_window->draw(circle); }
