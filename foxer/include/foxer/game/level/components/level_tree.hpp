#ifndef FOX_LEVEL_TREE_HPP
#define FOX_LEVEL_TREE_HPP

namespace fox {

struct LevelNode {
  std::unique_ptr<Level> level;
  std::vector<std::unique_ptr<LevelNode>> children;
};

class LevelTree {};

} // namespace fox

#endif
