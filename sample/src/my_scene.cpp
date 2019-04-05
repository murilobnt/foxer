#include "my_scene.hpp"

void MyScene::start() {
  m_level.load(std::vector<std::string>{"assets/tileset02.png",
                                        "assets/steampunkish-tilec.png"},
               "assets/level01.json");
}

void MyScene::update() {
  // we'll do nothing over here
}

void MyScene::draw_entities() { app_window->draw(m_level); }
