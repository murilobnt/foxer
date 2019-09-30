// File: texture_loader.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2019 Murilo Bento
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

#ifndef FOX_TEXTURE_LOADER_HPP_
#define FOX_TEXTURE_LOADER_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <string>

#include "foxer/external/collision.h"

// Texture loader is a tool to ease the loading of textures.

namespace fox {

class TextureLoader {
public:
  // Set the given texture with the image from the given path, with
  // the given width and height, also defining if the texture is repeated
  // or if has bitmask.
  static void set_texture_from_file(sf::Texture &texture_to_be_loaded,
                                    std::string path, bool is_repeated = false,
                                    bool has_bitmask = false);

  // Create the given texture with the given width and height.
  static void create_texture(sf::Texture &texture, int w, int h);

private:
  // Load the given texture by the path to its corresponding image.
  static void load_texture(sf::Texture &texture, std::string path);
};

} // namespace fox

#endif
