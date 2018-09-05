#include "gs2d_engine/other/geared_up/simple_menu_scene.hpp"

namespace gs {

SimpleMenuScene::SimpleMenuScene(std::string background_texture_path,
                                 int w, int h)
{
        TextureLoader::set_texture_from_file(background_texture,
                                             background_texture_path,
                                             w, h);
}

void SimpleMenuScene::start(){
        background.setTexture(background_texture);
        delayed_start();
        ui_button_vec_it = ui_button_vec.begin();
}

void SimpleMenuScene::update(){
        delayed_update();
}

void SimpleMenuScene::handle_event(sf::Event &event){
        delayed_handle_event(event);
}

void SimpleMenuScene::draw_entities(){
        app_window->draw(background);
        for(int i = 0; i < ui_button_vec.size(); ++i) {
                UIButton button = ui_button_vec[i];
                app_window->draw(button.get_sprite());
                app_window->draw(button.get_button_text());
        }

        for(int i = 0; i < ui_text_vec.size(); ++i)
                app_window->draw(ui_text_vec[i]);

        delayed_draw();
}

void SimpleMenuScene::add_button(UIButton& button){
        ui_button_vec.push_back(button);
}

void SimpleMenuScene::add_text(sf::Text& text){
        ui_text_vec.push_back(text);
}

void SimpleMenuScene::delayed_update(){

}

void SimpleMenuScene::delayed_draw(){

}

}
