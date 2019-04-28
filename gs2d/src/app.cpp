#include "gs2d/app_cycle/app.hpp"

namespace gs {

App::App() {}

App::App(int app_width, int app_height, std::string app_title, float timestep,
         float limit_framerate)
    : app_frequency(sf::seconds(1.f / timestep)), app_title(app_title),
      app_width(app_width), app_height(app_height), dt(1.f / timestep),
      limit_framerate(limit_framerate) {}

App::~App() { delete app_window; }

void App::app_start(Scene *first_scene, bool vsync, bool fullscreen) {

  app_window =
      (fullscreen ? new sf::RenderWindow(sf::VideoMode(app_width, app_height),
                                         app_title, sf::Style::Fullscreen)
                  : new sf::RenderWindow(sf::VideoMode(app_width, app_height),
                                         app_title));
  app_window->setVerticalSyncEnabled(vsync);
  if (limit_framerate > 0)
    app_window->setFramerateLimit(limit_framerate);

  SceneBuilder::build_scene(first_scene, app_window, &app_state, dt,
                            &clock_handler);
  std::shared_ptr<Scene> first_scene_ptr(first_scene);
  app_state.push_back(first_scene_ptr);
  app_state.back()->start();

  while (app_window->isOpen()) {
    process_events();
    while (app_frequency.time_to_update())
      app_state.back()->update();
    clear_and_draw();

    clock_handler.restart_clock();
    clock_handler.restart_time_handler(&app_frequency);
    app_state.back()->reset_time_handlers(clock_handler);
  }
}

void App::process_events() {
  sf::Event event;

  while (app_window->pollEvent(event)) {
    app_state.back()->handle_event(event);
  }
}

void App::clear_and_draw() {
  app_window->clear();
  app_state.back()->draw_entities();
  app_window->display();
}

int App::get_app_width() const { return app_width; }

int App::get_app_height() const { return app_height; }

} // namespace gs
