// File: textureloader.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _TEXTURELOADER_HPP_
#define _TEXTURELOADER_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <string>

#include "external/collision.h"

// Texture loader is a tool to ease the loading of textures.

class TextureLoader {
private:
  // The texture.
  sf::Texture texture;

  // Load the given texture by the path to its corresponding image.
  void loadTexture(sf::Texture &texture, std::string pathToImage);

  // Create the given texture with the given width and height.
  void createTexture(sf::Texture &texture, int w, int h);

public:
  // Constructor.
  TextureLoader();

  // Set the given texture with the image from the given path, with
  // the given width and height, also defining if the texture is repeated
  // or if has bitmask.
  void setTextureFromFile(sf::Texture &textureToBeLoaded,
                          std::string pathToImage, int w, int h,
                          bool isRepeated = false, bool hasBitmask = false);
};

#endif
