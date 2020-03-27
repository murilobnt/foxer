#include "level_test.hpp"

LevelTest::LevelTest() : RPGLevelIndoor("assets/levels/level_test.json") {}

LevelTest::LevelTest(const std::string &start_position_id)
    : RPGLevelIndoor("assets/levels/level_test.json", start_position_id) {}

void LevelTest::level_init() {
  initialise_camera();
}

void LevelTest::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 2));
  target.draw(*player);
}
