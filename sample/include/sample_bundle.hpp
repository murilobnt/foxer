#ifndef SAMPLE_BUNDLE_HPP
#define SAMPLE_BUNDLE_HPP

#include <SFML/Graphics.hpp>
#include <gs2d/scene/components/object/main_object.hpp>

struct SampleBundle {
  gs::MainObject *character;
  sf::Vector2f *delay;

  SampleBundle();
  SampleBundle(gs::MainObject *character, sf::Vector2f *delay);
};

#endif
