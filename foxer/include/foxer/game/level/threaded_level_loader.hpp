#ifndef FOX_THREADED_LEVEL_LOADER_HPP
#define FOX_THREADED_LEVEL_LOADER_HPP

#include "foxer/game/level/level.hpp"
#include <thread>

namespace fox {

class ThreadedLevelLoader {
private:
  std::shared_ptr<Level> level;
  std::thread level_loader;

  void load_level();

public:
  ~ThreadedLevelLoader();
  void run(std::shared_ptr<Level> level);
  std::shared_ptr<Level> get_level();
};

} // namespace fox

#endif
