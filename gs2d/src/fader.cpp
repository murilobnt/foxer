#include "gs2d/other/helpers/fader.hpp"

namespace gs {

void Fader::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(fader);
}

Fader::Fader() {}

Fader::Fader(sf::Vector2f size) : fader(size) {
  fade_state = NOT_FADING;
  fader.setFillColor(sf::Color(0, 0, 0));
}

Fader::Fader(sf::Vector2f size, sf::Vector2f position) : fader(size) {
  fade_state = NOT_FADING;
  fader.setFillColor(sf::Color(0, 0, 0));
  fader.setPosition(position);
}

bool Fader::fade_in(short speed) {
  alpha = (alpha - speed < 0 ? 0 : alpha - speed);
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  if (alpha == 0) {
    fade_state = NOT_FADING;
    return true;
  }
  return false;
}

bool Fader::fade_out(short speed) {
  alpha = (alpha + speed > 255 ? 255 : alpha + speed);
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  if (alpha == 255) {
    return true;
  }
  return false;
}

void Fader::start_fade_in() {
  alpha = 255;
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  fade_state = FADING_IN;
}

void Fader::start_fade_out() {
  alpha = 0;
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
  fade_state = FADING_OUT;
}

FadeState Fader::get_fade_state() const { return fade_state; }

} // namespace gs
