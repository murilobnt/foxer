#include "gs2d_engine/ui_components/ui_button.hpp"

namespace gs {

UIButton::UIButton(int id, float x, float y,
                   sf::Texture const& texture,
                   sf::Vector2i sprite_pos_at_tex,
                   sf::Vector2i sprite_dimensions,
                   sf::Font& font, std::string text_content)
        : SpritedEntity::SpritedEntity(texture, sprite_pos_at_tex,
                                       sprite_dimensions) {
        this->id = id;
        set_focused(false);

        set_sprite_position(x, y);
        init_text(font, text_content);
}

UIButton::UIButton()
        : SpritedEntity() {

}

void UIButton::set_focused(bool focused){
        set_sprite_color((focused ? sf::Color::Cyan : sf::Color(255, 255, 255)));
        this->focused = focused;
}

bool UIButton::is_focused(){
        return focused;
}

sf::Text& UIButton::get_button_text(){
        return button_text;
}

int UIButton::get_id(){
        return id;
}

void UIButton::init_text(sf::Font& font, std::string text_content){
        button_text.setFont(font);
        button_text.setString(text_content);

        button_text.setPosition(get_sprite_position().x + get_sprite_local_bounds().width/2 - button_text.getLocalBounds().width/2, get_sprite_position().y);
}

}
