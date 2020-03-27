#ifndef FOX_FOXER_LEVEL_HPP_
#define FOX_FOXER_LEVEL_HPP_

#include <memory>

#include "foxer/game/level/level.hpp"
#include "foxer/game/level/tld_loader.hpp"
#include "foxer/scene/components/object/main_object.hpp"
#include "foxer/game/level/level_bundle.hpp"
#include "foxer/game/level/level_collision_verifier.hpp"
#include "foxer/other/geared_up/default_level_col_verifier.hpp"

namespace fox {

class FoxerLevel : public Level {
public:
  FoxerLevel();
  FoxerLevel(const std::string &level_path, LevelBundle *bundle,
             std::unique_ptr<LevelCollisionVerifier> col_ver =
             std::make_unique<DefaultLevelColVerifier>());

  void set_level_bundle(LevelBundle *bundle);
  void change_level(Level *level);
  void change_level(std::shared_ptr<Level> level);

  // ===================== Inherited from Level ================================
  virtual void load();
  virtual void handle_events(const float &delta_time);
  virtual void init() = 0;
  virtual void control_camera(const float &delta_time) = 0;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;
  // ===========================================================================
private:
  std::string level_path;

  TiledLevelData data;
  TextureHolder tex_holder;
  std::unique_ptr<LevelCollisionVerifier> col_ver;
  LevelBundle *bundle;
};

}

#endif
