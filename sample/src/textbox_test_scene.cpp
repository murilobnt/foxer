#include "textbox_test_scene.hpp"

void TextBoxTestScene::start() {
  begin = false;
  sf::Vector2u window_size = fox::Scene::app_window->getSize();
  box = Textbox(ltex_repo.load("assets/textures/box-highres.png", true),
                window_size);
  font.loadFromFile("assets/fonts/Ubuntu-C.ttf");
  text = fox::Text(font,
                   sf::Vector2u(window_size.x - 25, window_size.y - 25),
                   sf::Vector2f(25, fox::Scene::app_window->getSize().y - 175),
                   120.f);
  time_handlers.push_back(text.get_time_handler());
  text.display_text("Lorem\nipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
}

void TextBoxTestScene::update() {
  if(text.is_full() && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    text.get_time_handler()->set_update_rate(sf::seconds(1.f/60.f));
    text.clear_text();
    text.reset_last_update();
  }

  if(!begin && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    begin = true;
    text.reset_last_update();
  }

  if(begin && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    text.get_time_handler()->set_update_rate(sf::seconds(1.f/240.f));
}

// TODO: "Free" update (not bound to a timestep).

void TextBoxTestScene::draw_entities() {
  if(begin){
    text.time_trigger();
    app_window->draw(box);
    app_window->draw(text);
  }
}
