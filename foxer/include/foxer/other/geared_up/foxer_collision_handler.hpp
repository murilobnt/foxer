// File: foxer_collision_handler.hpp
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

#ifndef FOX_FOXER_COLLISION_HANDLER_HPP_
#define FOX_FOXER_COLLISION_HANDLER_HPP_

#include "foxer/game/level/collision_handler.hpp"
#include "foxer/scene/components/object/game_object.hpp"
#include "foxer/other/helpers/tile_grid.hpp"

namespace fox {

// The default collision handler used by FoxerLevel.

class FoxerCollisionHandler : public CollisionHandler {
public:

  // Constructor.
  FoxerCollisionHandler(GameObject *go, const TileGrid &level_tile_grid);

  // ==================== Implemented from CollisionHandler ====================
  virtual void handle_collision();
  // ===========================================================================

private:
  // A reference to the player.
  GameObject *go;

  // The const reference to the collision tile grid.
  const TileGrid &level_tile_grid;
};

}

#endif
