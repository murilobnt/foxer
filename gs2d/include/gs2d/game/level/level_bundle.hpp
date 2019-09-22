#ifndef GS_LEVEL_BUNDLE_HPP
#define GS_LEVEL_BUNDLE_HPP

#include "gs2d/game/level/level_proxy.hpp"
#include "gs2d/other/helpers/shared_texture_holder.hpp"
#include "gs2d/scene/components/camera/camera.hpp"

namespace gs {

struct LevelBundle {
  LevelProxy *level_proxy;
  SharedTextureHolder *shared_holder;
  Camera *camera;

  LevelBundle();
  explicit LevelBundle(LevelProxy *level_proxy,
                       SharedTextureHolder *shared_holder, Camera *camera);
};

} // namespace gs

#endif
