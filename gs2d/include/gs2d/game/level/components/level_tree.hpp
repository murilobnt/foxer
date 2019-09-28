#ifndef GS_LEVEL_TREE_HPP
#define GS_LEVEL_TREE_HPP

namespace gs {

struct LevelNode {
  std::unique_ptr<Level> level;
  std::vector<std::unique_ptr<LevelNode>> children;
};

class LevelTree {};

} // namespace gs

#endif
