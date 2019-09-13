#ifndef GS_THREADED_LEVEL_LOADER_HPP
#define GS_THREADED_LEVEL_LOADER_HPP

#include "gs2d/game/level/level.hpp"
#include "gs2d/other/helpers/resource_manager.hpp"
#include <thread>

namespace gs {

class ThreadedLevelLoader {
private:
  std::shared_ptr<Level> level;
  std::thread level_loader;

  void load_level();

public:
  ~ThreadedLevelLoader();
  void run(Level *level, ResourceManager tex_manager);
  std::shared_ptr<Level> get_level();
};

} // namespace gs

#endif
