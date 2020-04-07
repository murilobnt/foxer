#include "foxer/components/text.hpp"

namespace fox {

TextAnimationControl::TextAnimationControl() :
complete(true),
full(false) {}

TextAnimationControl::TextAnimationControl(bool complete) :
complete(complete),
full(false){}

Text::Text(){}

Text::Text(const sf::Font &font, const sf::Vector2u container_size,
           const sf::Vector2f &pos, float update_rate) :
TimedEntity(sf::seconds(1.f / update_rate)),
container_size(container_size)
{
  text.setPosition(pos);
  text.setCharacterSize(40);
  text.setFont(font);
}

void Text::tokenize_text(const std::string &text){
  std::stringstream str_strm(text);
  std::string tmp;
  char delim = ' ';

  while (std::getline(str_strm, tmp, delim))
    tac.tokenized_text.push(tmp);
}

void Text::clear_text() {
  text.setString("");
  tac.full = false;
}

const bool &Text::is_full() const {
  return tac.full;
}

void Text::display_text(const std::string &what) {
  tac = TextAnimationControl(false);
  tokenize_text(what);
  tac.current_word = tac.tokenized_text.front();
  tac.text_iterator = tac.current_word.begin();
}

void Text::on_update_time(){
  if(!tac.complete && !tac.full){
    if(tac.text_iterator == tac.current_word.end()){

      tac.tokenized_text.pop();

      if(tac.tokenized_text.empty()){
        tac.complete = true;
        return;
      }

      tac.current_word = tac.tokenized_text.front();
      tac.text_iterator = tac.current_word.begin();

      tac.copy = text;
      text.setString(text.getString() + " ");
      tac.text_rect = text.getGlobalBounds();
      if(tac.text_rect.left + tac.text_rect.width > container_size.x)
        text = tac.copy;
    }

    if(tac.text_iterator == tac.current_word.begin()){
      tac.copy = text;
      text.setString(text.getString() + tac.current_word);
      tac.text_rect = text.getGlobalBounds();
      if(tac.text_rect.left + tac.text_rect.width > container_size.x){
        tac.copy.setString(tac.copy.getString() + "\n");
        tac.text_rect = tac.copy.getGlobalBounds();
        if(tac.text_rect.top + tac.text_rect.height > container_size.y)
          tac.full = true;
      }
      text = tac.copy;
      if(tac.full)
        return;
    }

    text.setString(text.getString() + *tac.text_iterator);
    ++tac.text_iterator;
  }
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(text);
}

}
