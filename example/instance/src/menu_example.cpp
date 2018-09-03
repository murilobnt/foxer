#include "menu_example.hpp"

MenuExample::MenuExample()
        : gs::SimpleMenuScene(std::string
                                  ("../../gs2d/assets/7579418_altered.png"),
                          800, 600){

}

void MenuExample::delayed_start() {
        gs::TextureLoader::set_texture_from_file(button_background_texture,
                                             std::string("../../gs2d/assets/uibutton.png"),
                                             250, 35);

        button_font.loadFromFile("../../gs2d/assets/Muli/Muli-Bold.ttf");

        goto_test_scene = gs::UIButton(1, 0, 225, button_background_texture,
                                   sf::Vector2i(0, 0), sf::Vector2i(250, 35),
                                   button_font, std::string("Test"));
        goto_second_scene = gs::UIButton(2, 0, 300, button_background_texture,
                                     sf::Vector2i(0, 0), sf::Vector2i(250, 35),
                                     button_font, std::string("Second"));

        add_button(goto_test_scene);
        add_button(goto_second_scene);

        ui_button_vec[0].set_focused(true);
}

void MenuExample::delayed_handle_event(sf::Event &event){
        switch(event.type) {
        case sf::Event::Closed:
            app_window->close();
        break;
        case sf::Event::KeyReleased:
                switch(event.key.code) {
                case sf::Keyboard::Z:
                case sf::Keyboard::Return:
                case sf::Keyboard::Space:
                        switch((*ui_button_vec_it).get_id()) {
                        case 1:
                                change_scene(new TestScene());
                                break;
                        case 2:
                                change_scene(new SecondScene());
                                break;
                        }
                        break;
                case sf::Keyboard::Up:
                case sf::Keyboard::Down:
                        (*ui_button_vec_it).set_focused(false);
                        if(ui_button_vec_it == ui_button_vec.end() - 1)
                                ui_button_vec_it = ui_button_vec.begin();
                        else
                                ui_button_vec_it = ui_button_vec.end() - 1;
                        (*ui_button_vec_it).set_focused(true);
                        break;
                }
                break;
        }
}
