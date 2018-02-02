#ifndef _TEXTUREMANAGER_HPP_
#define _TEXTUREMANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/concrete/textureloader.hpp"
#include "gamesimple/enum/textureindex.hpp"

class TextureManager {
public:
  virtual sf::Texture &getTexture(TextureIndex index) = 0;
};

#endif
