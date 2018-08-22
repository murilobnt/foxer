#include "gs2d_engine/concrete/game.hpp"

namespace gs {

Game::Game(int game_width, int game_height,
           std::string game_title, float framerate)
        : game_screen(sf::VideoMode(game_width, game_height), game_title),
        game_frequency(sf::seconds(1.f / framerate)) {
        this->game_width = game_width;
        this->game_height = game_height;
}

void Game::game_start(Scene *first_scene, bool vsync) {
        game_screen.setVerticalSyncEnabled(vsync);
        first_scene->set_scene_manager(&scene_manager);
        scene_manager.set_scene(first_scene);

        while (game_screen.isOpen()) {
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

        while (game_screen.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                        game_screen.close();
                }

                scene_manager.handle_event(event, game_screen);
        }
}

void Game::clear_and_draw() {
        game_screen.clear();
        scene_manager.draw_entities(game_screen);
        game_screen.display();
}

int Game::get_game_width() const {
        return game_width;
}

int Game::get_game_height() const {
        return game_height;
}

}
