#ifndef LEVEL_TEST_HPP_
#define LEVEL_TEST_HPP_

#include <foxer/level.hpp>

class LevelTest : public fox::RPGLevelIndoor {
public:
  LevelTest();
  explicit LevelTest(const std::string &start_position_id);

private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void level_init();
};

#endif
