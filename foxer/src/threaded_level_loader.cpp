#include "foxer/logical/threaded_level_loader.hpp"

namespace fox {

ThreadedLevelLoader::~ThreadedLevelLoader() {
  if (level_loader.joinable())
    level_loader.join();
}

void ThreadedLevelLoader::load_level() { level->load(); }

void ThreadedLevelLoader::run(std::shared_ptr<Level> level) {
  this->level = level;
  level_loader = std::thread(&ThreadedLevelLoader::load_level, this);
}

std::shared_ptr<Level> ThreadedLevelLoader::get_level() {
  level_loader.join();
  return level;
}

} // namespace fox
