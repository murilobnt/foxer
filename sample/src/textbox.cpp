#include "textbox.hpp"

Textbox::Textbox(){

}

Textbox::Textbox(const sf::Texture &bg_texture,
                 const sf::Vector2u &window_size)
                 : window_size(window_size),
                   bg_texture(bg_texture)
{
  load();
}

void Textbox::set_window_size(const sf::Vector2u &window_size){
  this->window_size = window_size;
}

void Textbox::load() {
  tb_va.setPrimitiveType(sf::Quads);
  tb_va.resize(3 * 4);

  sf::Vertex* quad = &tb_va[0];

  float y_scale = (window_size.y / 768.f) * 200;
  if(y_scale > 200)
    y_scale = 200;

  quad[0].position = sf::Vector2f(50, window_size.y - y_scale);
  quad[1].position = sf::Vector2f(window_size.x - 50, window_size.y - y_scale);
  quad[2].position = sf::Vector2f(window_size.x - 50, window_size.y);
  quad[3].position = sf::Vector2f(50, window_size.y);

  quad[0].texCoords = sf::Vector2f(50, 0);
  quad[1].texCoords = sf::Vector2f(150, 0);
  quad[2].texCoords = sf::Vector2f(150, 200);
  quad[3].texCoords = sf::Vector2f(50, 200);

  quad = &tb_va[1 * 4];

  quad[0].position = sf::Vector2f(0, window_size.y - y_scale);
  quad[1].position = sf::Vector2f(50, window_size.y - y_scale);
  quad[2].position = sf::Vector2f(50, window_size.y);
  quad[3].position = sf::Vector2f(0, window_size.y);

  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(50, 0);
  quad[2].texCoords = sf::Vector2f(50, 200);
  quad[3].texCoords = sf::Vector2f(0, 200);

  quad = &tb_va[2 * 4];

  quad[0].position = sf::Vector2f(window_size.x - 50, window_size.y - y_scale);
  quad[1].position = sf::Vector2f(window_size.x, window_size.y - y_scale);
  quad[2].position = sf::Vector2f(window_size.x, window_size.y);
  quad[3].position = sf::Vector2f(window_size.x - 50, window_size.y);

  quad[0].texCoords = sf::Vector2f(150, 0);
  quad[1].texCoords = sf::Vector2f(200, 0);
  quad[2].texCoords = sf::Vector2f(200, 200);
  quad[3].texCoords = sf::Vector2f(150, 200);
}

void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &bg_texture;
  target.draw(tb_va, states);
}
