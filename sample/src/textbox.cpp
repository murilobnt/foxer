#include "textbox.hpp"

Textbox::Textbox(){

}

Textbox::Textbox(const sf::Font     &font,
                 const sf::Vector2f &box_position,
                 const sf::Texture  &box_texture,
                 const sf::Vector2u &box_size,
                 float              update_rate,
                 short              margin)
                 : box_texture(box_texture),
                   box_position(box_position),
                   box_size(box_size),
                   active(false)
{
  load();
  text = fox::Text(font,
                   sf::Vector2u(box_size.x - (margin * 2), box_size.y - (margin * 2)) ,
                   sf::Vector2f(box_position.x + margin, box_position.y + margin),
                   update_rate);
}

void Textbox::load() {
  tb_va.setPrimitiveType(sf::Quads);
  tb_va.resize(3 * 4);

  sf::Vertex* quad = &tb_va[0];

  // Middle. Ideal height: 50.

  quad[0].position = sf::Vector2f(box_position.x + 50, box_position.y);
  quad[1].position = sf::Vector2f(box_position.x + box_size.x - 50, box_position.y);
  quad[2].position = sf::Vector2f(box_position.x + box_size.x - 50, box_position.y + box_size.y);
  quad[3].position = sf::Vector2f(box_position.x + 50, box_position.y + box_size.y);

  quad[0].texCoords = sf::Vector2f(50, 0);
  quad[1].texCoords = sf::Vector2f(150, 0);
  quad[2].texCoords = sf::Vector2f(150, 200);
  quad[3].texCoords = sf::Vector2f(50, 200);

  quad = &tb_va[1 * 4];

  // Left. Ideal size: 50.

  quad[0].position = sf::Vector2f(box_position.x, box_position.y);
  quad[1].position = sf::Vector2f(box_position.x + 50, box_position.y);
  quad[2].position = sf::Vector2f(box_position.x + 50, box_position.y + box_size.y);
  quad[3].position = sf::Vector2f(box_position.x, box_position.y + box_size.y);

  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(50, 0);
  quad[2].texCoords = sf::Vector2f(50, 200);
  quad[3].texCoords = sf::Vector2f(0, 200);

  quad = &tb_va[2 * 4];

  // Right. Ideal size: 50.

  quad[0].position = sf::Vector2f(box_position.x + box_size.x - 50, box_position.y);
  quad[1].position = sf::Vector2f(box_position.x + box_size.x, box_position.y);
  quad[2].position = sf::Vector2f(box_position.x + box_size.x, box_position.y + box_size.y);
  quad[3].position = sf::Vector2f(box_position.x + box_size.x - 50, box_position.y + box_size.y);

  quad[0].texCoords = sf::Vector2f(150, 0);
  quad[1].texCoords = sf::Vector2f(200, 0);
  quad[2].texCoords = sf::Vector2f(200, 200);
  quad[3].texCoords = sf::Vector2f(150, 200);
}

fox::TimeHandler *Textbox::get_text_time_handler(){
  return text.get_time_handler();
}

const bool &Textbox::is_active() const{
  return active;
}

void Textbox::display_text(const std::string &what){
  text.display_text(what);
}

void Textbox::start(){
  if(!text.is_complete()){
    text.reset_last_update();
    active = true;
  }
}

void Textbox::update_text_state(){
  text.time_trigger();
}

void Textbox::next(){
  if(text.is_full()){
    text.clear_text();
    text.reset_last_update();
  }
  if(text.is_complete()){
    active = false;
  }
}

void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &box_texture;
  target.draw(tb_va, states);
  target.draw(text);
}
