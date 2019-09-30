#ifndef FOX_LEVEL_BUNDLE_HPP
#define FOX_LEVEL_BUNDLE_HPP

#include "foxer/game/level/level_proxy.hpp"
#include "foxer/other/helpers/shared_texture_holder.hpp"
#include "foxer/scene/components/camera/camera.hpp"

namespace fox {

struct LevelBundle {
  LevelProxy *level_proxy;
  SharedTextureHolder *shared_holder;
  Camera *camera;

  LevelBundle();
  explicit LevelBundle(LevelProxy *level_proxy,
                       SharedTextureHolder *shared_holder, Camera *camera);
};

} // namespace fox

#endif
