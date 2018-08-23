#include "second_scene.hpp"
#include "menu_example.hpp"

void SecondScene::start() {
        shape = sf::CircleShape(100.f);
        shape.setFillColor(sf::Color::Green);
}

void SecondScene::update() {
}

void SecondScene::handle_event(sf::Event &event) {
        switch (event.type) {
        case sf::Event::Closed:
            app_window->close();
        break;
        case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                        change_scene(new MenuExample());
                        break;
                }
                break;
        }
}

void SecondScene::draw_entities() {
        app_window->draw(shape);
}
