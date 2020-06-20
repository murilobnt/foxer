#include "textbox_test_scene.hpp"

void TextBoxTestScene::start() {
  begin = false;
  sf::Vector2u window_size = fox::Scene::app_window->getSize();
  float y_scale = (window_size.y / 768.f) * 200;
  if(y_scale > 200)
    y_scale = 200;
  font.loadFromFile("assets/fonts/Ubuntu-C.ttf");
  box = Textbox(font,
                sf::Vector2f(0, window_size.y - 200),
                ltex_repo.load("assets/textures/box-highres.png", true),
                sf::Vector2u(window_size.x, y_scale));
  time_handlers.push_back(box.get_text_time_handler());
  box.display_text("Lorem\nipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
}

void TextBoxTestScene::update() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    if(box.is_active())
      box.next();
    else
      box.start();
  }

  if(box.is_active())
    box.update_text_state();
}

void TextBoxTestScene::draw_entities() {
  if(box.is_active()){
    app_window->draw(box);
  }
}
