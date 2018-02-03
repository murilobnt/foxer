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
