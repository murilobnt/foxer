#include "foxer/components/textbox.hpp"

namespace fox {

Textbox::Textbox(){

}

Textbox::Textbox(const sf::Font     &font,
                 const sf::Vector2f &box_position,
                 const sf::Texture  &box_texture,
                 const sf::Vector2u &box_size,
                 unsigned int       char_size,
                 float              update_rate,
                 short              margin)
                 : box_texture(box_texture),
                   box_position(box_position),
                   box_size(box_size),
                   margin(margin),
                   active(false)
{
  load();
  text = Text(font,
              sf::Vector2u(box_size.x - (margin * 2), box_size.y - (margin * 2)) ,
              sf::Vector2f(box_position.x + margin, box_position.y + margin),
              update_rate,
              char_size);
}

void Textbox::load() {
  tb_va.setPrimitiveType(sf::Quads);
  tb_va.resize(9 * 4);

  sf::Vertex* quad = &tb_va[0];

  // Up left.

  quad[0].position = sf::Vector2f(box_position.x, box_position.y);
  quad[1].position = sf::Vector2f(box_position.x + 50, box_position.y);
  quad[2].position = sf::Vector2f(box_position.x + 50, box_position.y + 50);
  quad[3].position = sf::Vector2f(box_position.x, box_position.y + 50);

  quad[0].texCoords = sf::Vector2f(0, 0);
  quad[1].texCoords = sf::Vector2f(50, 0);
  quad[2].texCoords = sf::Vector2f(50, 50);
  quad[3].texCoords = sf::Vector2f(0, 50);

  // Up.

  quad = &tb_va[1 * 4];

  quad[0].position = sf::Vector2f(box_position.x + 50, box_position.y);
  quad[1].position = sf::Vector2f(box_size.x - 50, box_position.y);
  quad[2].position = sf::Vector2f(box_size.x - 50, box_position.y + 50);
  quad[3].position = sf::Vector2f(box_position.x + 50, box_position.y + 50);

  quad[0].texCoords = sf::Vector2f(50, 0);
  quad[1].texCoords = sf::Vector2f(150, 0);
  quad[2].texCoords = sf::Vector2f(150, 50);
  quad[3].texCoords = sf::Vector2f(50, 50);

  // Right up.

  quad = &tb_va[2 * 4];

  quad[0].position = sf::Vector2f(box_size.x - 50, box_position.y);
  quad[1].position = sf::Vector2f(box_size.x, box_position.y);
  quad[2].position = sf::Vector2f(box_size.x, box_position.y + 50);
  quad[3].position = sf::Vector2f(box_size.x - 50, box_position.y + 50);

  quad[0].texCoords = sf::Vector2f(150, 0);
  quad[1].texCoords = sf::Vector2f(200, 0);
  quad[2].texCoords = sf::Vector2f(200, 50);
  quad[3].texCoords = sf::Vector2f(150, 50);

  quad = &tb_va[3 * 4];

  // Middle Left.

  quad[0].position = sf::Vector2f(box_position.x, box_position.y + 50);
  quad[1].position = sf::Vector2f(box_position.x + 50, box_position.y + 50);
  quad[2].position = sf::Vector2f(box_position.x + 50, box_size.y - 50);
  quad[3].position = sf::Vector2f(box_position.x, box_size.y - 50);

  quad[0].texCoords = sf::Vector2f(0, 50);
  quad[1].texCoords = sf::Vector2f(50, 50);
  quad[2].texCoords = sf::Vector2f(50, 150);
  quad[3].texCoords = sf::Vector2f(0, 150);

  quad = &tb_va[4 * 4];

  // Middle Right.

  quad[0].position = sf::Vector2f(box_size.x - 50, box_position.y + 50);
  quad[1].position = sf::Vector2f(box_size.x, box_position.y + 50);
  quad[2].position = sf::Vector2f(box_size.x, box_size.y - 50);
  quad[3].position = sf::Vector2f(box_size.x - 50, box_size.y - 50);

  quad[0].texCoords = sf::Vector2f(150, 50);
  quad[1].texCoords = sf::Vector2f(200, 50);
  quad[2].texCoords = sf::Vector2f(200, 150);
  quad[3].texCoords = sf::Vector2f(150, 150);

  quad = &tb_va[5 * 4];

  // Bottom Left.

  quad[0].position = sf::Vector2f(box_position.x, box_size.y - 50);
  quad[1].position = sf::Vector2f(box_position.x + 50, box_size.y - 50);
  quad[2].position = sf::Vector2f(box_position.x + 50, box_size.y);
  quad[3].position = sf::Vector2f(box_position.x, box_size.y);

  quad[0].texCoords = sf::Vector2f(0, 150);
  quad[1].texCoords = sf::Vector2f(50, 150);
  quad[2].texCoords = sf::Vector2f(50, 200);
  quad[3].texCoords = sf::Vector2f(0, 200);

  quad = &tb_va[6 * 4];

  // Bottom Right.

  quad[0].position = sf::Vector2f(box_size.x - 50, box_size.y - 50);
  quad[1].position = sf::Vector2f(box_size.x, box_size.y - 50);
  quad[2].position = sf::Vector2f(box_size.x, box_size.y);
  quad[3].position = sf::Vector2f(box_size.x - 50, box_size.y);

  quad[0].texCoords = sf::Vector2f(150, 150);
  quad[1].texCoords = sf::Vector2f(200, 150);
  quad[2].texCoords = sf::Vector2f(200, 200);
  quad[3].texCoords = sf::Vector2f(150, 200);

  quad = &tb_va[7 * 4];

  // Middle Bottom.

  quad[0].position = sf::Vector2f(box_position.x + 50, box_size.y - 50);
  quad[1].position = sf::Vector2f(box_size.x - 50, box_size.y - 50);
  quad[2].position = sf::Vector2f(box_size.x - 50, box_size.y);
  quad[3].position = sf::Vector2f(box_position.x + 50, box_size.y);

  quad[0].texCoords = sf::Vector2f(50, 150);
  quad[1].texCoords = sf::Vector2f(150, 150);
  quad[2].texCoords = sf::Vector2f(150, 200);
  quad[3].texCoords = sf::Vector2f(50, 200);

  quad = &tb_va[8 * 4];

  // Middle.

  quad[0].position = sf::Vector2f(box_position.x + 50, box_position.y + 50);
  quad[1].position = sf::Vector2f(box_size.x - 50, box_position.y + 50);
  quad[2].position = sf::Vector2f(box_size.x - 50, box_size.y - 50);
  quad[3].position = sf::Vector2f(box_position.x + 50, box_size.y - 50);

  quad[0].texCoords = sf::Vector2f(50, 50);
  quad[1].texCoords = sf::Vector2f(150, 50);
  quad[2].texCoords = sf::Vector2f(150, 150);
  quad[3].texCoords = sf::Vector2f(50, 150);
}

TimeHandler *Textbox::get_text_time_handler(){
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

void Textbox::setPosition(float x, float y){
  sf::Transformable::setPosition(x, y);
  text.set_position(x + margin, y + margin);
}

void Textbox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = &box_texture;

  target.draw(tb_va, states);
  target.draw(text);
}

}
