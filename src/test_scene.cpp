#include "instance/test_scene.hpp"
#include "instance/menu_example.hpp"

TestScene::~TestScene(){
        std::cout << "My destructor have been called. Yay!" << std::endl;
}

void TestScene::start() {
        time_handlers.push_back(&character.get_animation_time_handler());

        TextureLoader::set_texture_from_file(char_texture,
                                             std::string("include/gs2d_engine/assets/link_edit.png"),
                                             1200, 1040);
        character = Character(char_texture,
                              0, 0, 120, 130, 0,
                              1200, 520, 910, 20);
        character.set_sprite_scale(0.4, 0.4);

        TextureLoader::set_texture_from_file(bg_texture,
                                             std::string("include/gs2d_engine/assets/7536921_orig.png"),
                                             1000, 750);
        bg = SpritedEntity(bg_texture, 0, 0, 1000, 750);

        character.set_sprite_position(sf::Vector2f(0, 0));
        bg.set_sprite_position(sf::Vector2f(0, 0));
}

void TestScene::update() {
        timed_events();
        character.control_entity();
        character.move_character();
}

void TestScene::handle_event(sf::Event event, sf::RenderWindow &screen) {
        switch (event.type) {
        case sf::Event::KeyReleased:
            switch(event.key.code){
            case sf::Keyboard::P:
                change_scene(SceneChanger::
                             create_scene(new SecondScene(),
                                          scene_manager));
                break;
            case sf::Keyboard::Escape:
                change_scene(SceneChanger::
                             create_scene(new MenuExample(),
                                          scene_manager));
                break;
            }
        }
}

void TestScene::draw_entities(sf::RenderWindow &window) {
        window.draw(bg.get_sprite());
        window.draw(character.get_sprite());
}

void TestScene::timed_events() {
        while (character.get_animation_time_handler().time_to_update())
                character.animate();
}
