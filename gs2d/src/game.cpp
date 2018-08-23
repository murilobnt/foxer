#include "gs2d_engine/concrete/game.hpp"

namespace gs {

Game::Game() {}

Game::Game(int game_width, int game_height,
           std::string game_title, float framerate)
        : game_frequency(sf::seconds(1.f / framerate)),
          game_title(game_title),
          game_width(game_width),
          game_height(game_height){

          }

Game::~Game(){
    delete app_window;
}

void Game::game_start(Scene *first_scene, bool vsync) {

        app_window = new sf::RenderWindow(sf::VideoMode(game_width, game_height), game_title);
        app_window->setVerticalSyncEnabled(vsync);

        first_scene->set_scene_manager(&scene_manager);
        first_scene->set_app_window(app_window);

        scene_manager.set_scene(first_scene);

        while (app_window->isOpen()) {
                handle_time_actions();
                clear_and_draw();

                clock_handler.restart_clock();
                clock_handler.restart_time_handler(&game_frequency);
                scene_manager.reset_time_handlers(clock_handler);
        }
}

void Game::handle_time_actions() {
        if (game_frequency.time_to_update()) {
                process_events();
                scene_manager.update();
        }
}

void Game::process_events() {
        sf::Event event;

        while (app_window->pollEvent(event)) {
                scene_manager.handle_event(event);
        }
}

void Game::clear_and_draw() {
        app_window->clear();
        scene_manager.draw_entities();
        app_window->display();
}

int Game::get_game_width() const {
        return game_width;
}

int Game::get_game_height() const {
        return game_height;
}

}
