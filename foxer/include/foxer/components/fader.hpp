#ifndef FOX_FADER_HPP_
#define FOX_FADER_HPP_

#include <SFML/Graphics.hpp>
#include "foxer/abstract_components/timed_entity.hpp"

namespace fox {

enum FadeState {
  COMPLETE,
  FADE_IN,
  FADE_OUT
};

class Fader : public sf::Sprite, public TimedEntity {
public:
  Fader();
  Fader(const sf::RenderTexture *rt, const sf::Time &update_rate);

  void fade_out();
  void fade_in();

  void on_update_time();
  bool is_complete();

private:
  int alpha;
  FadeState state;
};

}

#endif
