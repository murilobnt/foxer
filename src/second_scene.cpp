#include "instance/second_scene.hpp"
#include "instance/menu_example.hpp"

SecondScene::SecondScene(SceneManager *scene_manager)
        : Scene(scene_manager) {
}

SecondScene::SecondScene() : Scene::Scene() {
}

void SecondScene::start() {
        shape = sf::CircleShape(100.f);
        shape.setFillColor(sf::Color::Green);
}

void SecondScene::update() {
}

void SecondScene::handle_event(sf::Event event, sf::RenderWindow &screen) {
        switch (event.type) {
        case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Escape:
                        change_scene(SceneChanger::
                                     create_scene(new MenuExample(),
                                                  scene_manager));
                        break;
                }
                break;
        }
}

void SecondScene::draw_entities(sf::RenderWindow &window) {
        window.draw(shape);
}
