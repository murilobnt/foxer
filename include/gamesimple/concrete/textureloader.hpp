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

class TextureLoader {
private:
  // The texture
  sf::Texture texture;

  /**
   * Load the texture.
   * @param pathToImage the path to the image
   */
  void loadTexture(sf::Texture &texture, std::string pathToImage);

  /**
   * Create the texture.
   * @param w the width of the texture
   * @param h the height of the texture
   */
  void createTexture(sf::Texture &texture, int w, int h);

public:
  TextureLoader();

  void setTextureFromFile(sf::Texture &textureToBeLoaded,
                          std::string pathToImage, int w, int h,
                          bool isRepeated = false, bool hasBitmask = false);
};

#endif
