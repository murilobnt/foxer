#include "foxer/logical/shared_texture_repository.hpp"

namespace fox {

std::shared_ptr<sf::Texture>
SharedTextureRepository::load(const std::string &path, bool smooth,
                              bool repeated) {
  std::map<std::string, std::weak_ptr<sf::Texture>>::iterator it =
      holder.find(path);

  if (it == holder.end()) {
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path))
      throw std::runtime_error("TextureHolder error - Couldn't open file " +
                               path + ".");

    texture->setRepeated(repeated);
    texture->setSmooth(smooth);

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

      texture->setRepeated(repeated);
      texture->setSmooth(smooth);

      it->second = texture;
      return texture;
    }
  }
}

} // namespace fox
