#include "my_scene.hpp"

MyScene::MyScene() : delta_time(1.f/60.f), pause(false) {}

void MyScene::start() {
  physics_rate = fox::TimeHandler(sf::seconds(delta_time));

  character = Character(ltex_repo.load("assets/textures/character.png"));
  sf::Vector2u window_size = fox::Scene::app_window->getSize();
  y_scale = (480 / 768.f) * 200;
  if(y_scale > 200)
    y_scale = 200;

  font.loadFromFile("assets/fonts/Purisa.ttf");

  rt.create(640, 480);
  fader = fox::Fader(&rt, sf::seconds(1.f/400.f));

  bundle.camera = fox::Camera(sf::Vector2f(640, 480));
  textbox = fox::Textbox(font,
                         sf::Vector2f(0, 0),
                         ltex_repo.load("assets/textures/box-highres.png", true),
                         sf::Vector2u(640, y_scale),
                         18, 30.f);
  bundle.textbox = &textbox;
  bundle.stex_repo = &stex_repo;
  bundle.player_ref = &character;
  bundle.fader = &fader;

  std::shared_ptr<LevelOne> level_one =
      std::make_shared<LevelOne>(&character, &bundle);

  level_one->load();
  bundle.level_proxy.change_level(level_one);

  time_handlers.push_back(character.get_time_handler());
  time_handlers.push_back(&physics_rate);
  time_handlers.push_back(textbox.get_text_time_handler());
}

void MyScene::update() {
  if(!fader.is_complete())
    fader.time_trigger();

  while(physics_rate.time_to_update()){
    bundle.level_proxy.level_update(delta_time);
    bundle.level_proxy.control_camera(delta_time);
    fader.setPosition(bundle.camera.get_center().x - bundle.camera.get_size().x/2, bundle.camera.get_center().y - bundle.camera.get_size().y/2);
    textbox.setPosition(bundle.camera.get_center().x - bundle.camera.get_size().x/2, bundle.camera.get_center().y + bundle.camera.get_size().y/2 - y_scale);
  }
}

void MyScene::draw_entities() {
  rt.clear();
  app_window->setView(bundle.camera.get_view());
  app_window->draw(bundle.level_proxy);
  app_window->draw(fader);
}

void MyScene::handle_event(const sf::Event &event){
  Scene::handle_event(event);
  switch(event.type){
    case sf::Event::GainedFocus:
      pause = false;
    break;
    case sf::Event::LostFocus:
      pause = true;
    break;
  }
}

void MyScene::reset_time_handlers(fox::ClockHandler &clock_handler){
  if(!pause)
    Scene::reset_time_handlers(clock_handler);
  if(!fader.is_complete())
    clock_handler.restart_time_handler(fader.get_time_handler());
}
