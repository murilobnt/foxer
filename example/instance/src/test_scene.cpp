#include "test_scene.hpp"
#include "menu_example.hpp"

TestScene::~TestScene(){
        std::cout << "My destructor have been called. Yay!" << std::endl;
}

void TestScene::start() {
        camera = gs::Camera(sf::Vector2f(800, 600));

        test_tm.load("assets/images/test_tileset.png", "assets/levels/level00.csv",
                     sf::Vector2u(40, 40));

        time_handlers.push_back(&character.get_animation_time_handler());

        gs::TextureLoader::set_texture_from_file(char_texture,
                                             "assets/images/link_edit.png",
                                             1200, 1040);
        character = Character(char_texture,
                              sf::Vector2i(0, 0),
                              sf::Vector2i(120, 130),
                              sf::Vector2i(0, 1200),
                              sf::Vector2i(520, 910), 20);
        character.set_sprite_scale(0.4, 0.4);

        character.set_sprite_position(sf::Vector2f(0, 20));
}

void TestScene::update() {
        camera.center_at_sprite(character.get_sprite());
        app_window->setView(camera.get_view());
        timed_events();
        character.control_entity();
        character.move_character();
}

void TestScene::handle_event(sf::Event &event) {
        switch (event.type) {
        case sf::Event::Closed:
            app_window->close();
        break;
        case sf::Event::KeyReleased:
            switch(event.key.code){
            case sf::Keyboard::P:
                change_scene(new SecondScene());
                break;
            case sf::Keyboard::Escape:
                change_scene(new MenuExample());
                break;
            }
        }
}

void TestScene::draw_entities() {
        app_window->draw(test_tm);
        app_window->draw(character.get_sprite());
}

void TestScene::timed_events() {
        while (character.get_animation_time_handler().time_to_update())
                character.animate();
}

void TestScene::on_exit(){
    sf::Vector2u window_size = app_window->getSize();
    camera.center_at_position(sf::Vector2f(window_size.x/2, window_size.y/2));
    app_window->setView(camera.get_view());
}
