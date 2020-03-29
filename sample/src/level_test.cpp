#include "level_test.hpp"

LevelTest::LevelTest() {}

LevelTest::LevelTest(Character *player, fox::LevelBundle *bundle) :
                     FoxerLevel("assets/levels/level_test.json", bundle),
                     player(player) {}

void LevelTest::init(){}

void LevelTest::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 2));
  target.draw(*player);
}
