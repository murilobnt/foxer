#include "gs2d/other/helpers/shared_texture_holder.hpp"

namespace gs {

std::shared_ptr<sf::Texture>
SharedTextureHolder::load(const std::string &path) {
  std::map<std::string, std::weak_ptr<sf::Texture>>::iterator it =
      holder.find(path);

  if (it == holder.end()) {
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path))
      throw std::runtime_error("TextureHolder error - Couldn't open file " +
                               path + ".");
    holder.insert(std::make_pair(path, texture));
    return texture;
  } else {
    if (std::shared_ptr<sf::Texture> tex = it->second.lock()) {
      return tex;
    } else {
      std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
      if (!texture->loadFromFile(path))
        throw std::runtime_error("TextureHolder error - Couldn't open file " +
                                 path + ".");
      it->second = texture;
      return texture;
    }
  }
}

} // namespace gs
