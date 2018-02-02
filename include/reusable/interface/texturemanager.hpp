#ifndef _TEXTUREMANAGER_HPP_
#define _TEXTUREMANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "reusable/enum/textureindex.hpp"
#include "reusable/concrete/textureloader.hpp"

class TextureManager {
public:
  virtual sf::Texture &getTexture(TextureIndex index) = 0;
};

#endif
