#ifndef SAMPLE_LEVEL_HPP
#define SAMPLE_LEVEL_HPP

#include <gs2d/game/level/threaded_level_loader.hpp>
#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/other/helpers/fader.hpp>

#include "character.hpp"

class SampleLevel : public gs::TiledLevel {
private:
  bool fade_in;

  void handle_game_events(const float &delta_time);
  void handle_fade(const gs::FadeState &fade_state);

protected:
  Character *character;
  std::string start_position_id;

  gs::ThreadedLevelLoader *loader;
  gs::Fader fader;

  virtual void on_fade_out() = 0;
  virtual void on_fade_in() = 0;
  virtual void handle_level_events(const float &delta_time) = 0;
  virtual void level_init() = 0;

public:
  SampleLevel();
  SampleLevel(Character *character, gs::LevelProxy *level_proxy,
              const std::string &json_level,
              const std::string &start_position_id, bool fade_in = true);

  void init();
  void handle_events(const float &delta_time);
};

#endif
