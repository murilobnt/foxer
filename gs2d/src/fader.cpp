#include "gs2d/other/helpers/fader.hpp"

namespace gs {

void Fader::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(fader);
}

Fader::Fader() {}

Fader::Fader(sf::Vector2f size) : fader(size), in_fade(false) {
  fader.setFillColor(sf::Color(0, 0, 0));
}

Fader::Fader(sf::Vector2f size, sf::Vector2f position)
    : fader(size), in_fade(false) {
  fader.setFillColor(sf::Color(0, 0, 0));
  fader.setPosition(position);
}

bool Fader::fade_in(short speed) {
  if (!in_fade) {
    in_fade = true;
    alpha = 255;
  }
  alpha = (alpha - speed < 0 ? 0 : alpha - speed);
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  if (alpha == 0) {
    in_fade = false;
    return true;
  }
  return false;
}

bool Fader::fade_out(short speed) {
  if (!in_fade) {
    in_fade = true;
    alpha = 0;
  }
  alpha = (alpha + speed > 255 ? 255 : alpha + speed);
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  if (alpha == 255) {
    in_fade = false;
    return true;
  }
  return false;
}

bool Fader::get_in_fade() const { return in_fade; }

} // namespace gs
