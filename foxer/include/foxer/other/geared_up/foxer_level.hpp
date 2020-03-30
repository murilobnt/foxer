// File: foxer_level.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_FOXER_LEVEL_HPP_
#define FOX_FOXER_LEVEL_HPP_

#include <memory>

#include "foxer/game/level/level.hpp"
#include "foxer/game/level/tld_loader.hpp"
#include "foxer/scene/components/object/main_object.hpp"
#include "foxer/game/level/level_bundle.hpp"
#include "foxer/game/level/layer_container.hpp"
#include "foxer/game/level/collision_handler.hpp"
#include "foxer/other/geared_up/foxer_collision_handler.hpp"

namespace fox {

// The default level of the Foxer framework.
// It implements

class FoxerLevel : public Level {
public:
  // Constructors.
  FoxerLevel();
  FoxerLevel(const std::string &level_path, LevelBundle *bundle);

  // =================== Delegated functions to LevelProxy =====================
  void change_level(Level *level);
  void change_level(std::shared_ptr<Level> level);
  // ===========================================================================

  // Setter.
  void set_level_bundle(LevelBundle *bundle);

  // Getters.
  TileMap get_layer(int index) const;
  LayerContainer get_layers(const int &from, const int &to) const;
  LayerContainer get_layers() const;

  // ===================== Inherited from Level ================================
  virtual void init() = 0;
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;
  // ==================== Implemented from Level ===============================
  virtual void load();
  virtual void handle_events(const float &delta_time);
  virtual void control_camera(const float &delta_time);
  // ===========================================================================
protected:
  // Setter to the reference of the collision handler.
  void set_collision_handler(std::unique_ptr<CollisionHandler> col_ver);

private:
  // The string with the path of the JSON of the level.
  std::string level_path;

  // The data of the level (Tile layers, collision tiles and the map of events).
  TiledLevelData data;

  // The texture holder of the level. Loads and store textures.
  TextureHolder tex_holder;

  // The collision handler. It can be any child class of CollisionHandler,
  // but it is a FoxerCollisionHandler by default.
  std::unique_ptr<CollisionHandler> col_ver;

  // The reference to a bundle. The bundle better be created at the scene.
  LevelBundle *bundle;
};

}

#endif
