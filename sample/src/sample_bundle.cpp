#include "sample_bundle.hpp"

SampleBundle::SampleBundle() {}

SampleBundle::SampleBundle(gs::MainObject *character, sf::Vector2f *delay) {
  this->character = character;
  this->delay = delay;
}
