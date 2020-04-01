#ifndef FOX_FOXER_EXIT_AREA_CH_HPP_
#define FOX_FOXER_EXIT_AREA_CH_HPP_

#include <memory>

#include "foxer/app/level.hpp"
#include "foxer/abstract_components/collision_handler.hpp"
#include "foxer/logical/level_proxy.hpp"
#include "foxer/logical/threaded_level_loader.hpp"

namespace fox {

class FoxerExitAreaCH : public CollisionHandler {
public:
  FoxerExitAreaCH();
  FoxerExitAreaCH(LevelProxy *proxy,
                  std::shared_ptr<Level> next_level);

  // ==================== Implemented from CollisionHandler ====================
  virtual void handle_collision();
  // ===========================================================================

private:
  ThreadedLevelLoader loader;
  LevelProxy *proxy;
};

}

#endif
