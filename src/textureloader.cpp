#include "gamesimple/concrete/textureloader.hpp"

#include <string>

void TextureLoader::loadTexture(sf::Texture &texture,std::string pathToImage) {
        if (!texture.loadFromFile(pathToImage)) {
                // Error. Still need to do something if this occurs.
        }
}

void TextureLoader::createTexture(sf::Texture &texture, int w, int h) {
        if (!texture.create(w, h)) {
                // Error. Still need to do something if this occurs.
        }
}

void TextureLoader::setTextureFromFile(sf::Texture &textureToBeLoaded,
                                       std::string pathToImage,
                                       int w, int h,
                                       bool isRepeated, bool hasBitmask) {
        if (!hasBitmask)
                loadTexture(textureToBeLoaded, pathToImage);
        else
                Collision::CreateTextureAndBitmask(textureToBeLoaded,
                                                   pathToImage);

        createTexture(textureToBeLoaded, w, h);
        textureToBeLoaded.setRepeated(isRepeated);
}
