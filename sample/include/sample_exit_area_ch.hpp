#ifndef SAMPLE_EXIT_AREA_CH_HPP_
#define SAMPLE_EXIT_AREA_CH_HPP_

#include <foxer/logical.hpp>
#include <foxer/components.hpp>
#include <iostream>

class SampleExitAreaCH : public fox::FoxerExitAreaCH {
public:
  SampleExitAreaCH(fox::LevelProxy *level_proxy,
                   std::shared_ptr<fox::Level> next_level,
                   fox::Fader *fader);
  void handle_collision();

private:
  fox::Fader *fader;
  bool collided;
};

#endif
