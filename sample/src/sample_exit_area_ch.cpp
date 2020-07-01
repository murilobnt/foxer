#include "sample_exit_area_ch.hpp"

SampleExitAreaCH::SampleExitAreaCH(fox::LevelProxy *level_proxy,
                                   std::shared_ptr<fox::Level> next_level,
                                   fox::Fader *fader)
                                   : fox::FoxerExitAreaCH(level_proxy, next_level),
                                   fader(fader),
                                   collided(false){}

void SampleExitAreaCH::handle_collision() {
  if(!collided){
    fader->fade_out();
    collided = true;
  }

  if(fader->is_complete()){
    fox::FoxerExitAreaCH::handle_collision();
    fader->fade_in();
  }
}
