#include "gs2d/other/helpers/texture_holder.hpp"

namespace gs {

const sf::Texture &TextureHolder::load(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
    if (!resource->loadFromFile(path))
      throw std::runtime_error("TextureHolder error - Couldn't open file " +
                               path + ".");

    resources.insert(std::make_pair(path, resource));
    return *resources.at(path).get();
  } else {
    return *it->second;
  }
}

sf::Texture *TextureHolder::load_ptr(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
    if (!resource->loadFromFile(path))
      throw std::runtime_error("TextureHolder error - Couldn't open file " +
                               path + ".");

    resources.insert(std::make_pair(path, resource));
    return resources.at(path).get();
  } else {
    return it->second.get();
  }
}

std::shared_ptr<sf::Texture> TextureHolder::get(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    throw std::runtime_error("TextureHolder error - No entry on map for " +
                             path + ".");
  } else {
    return it->second;
  }
}

bool TextureHolder::has_texture(const std::string &path) {
  if (resources.find(path) == resources.end())
    return false;
  else
    return true;
}

void TextureHolder::set_texture(const std::string &path,
                                  std::shared_ptr<sf::Texture> resource) {
  resources.insert(std::make_pair(path, resource));
}

} // namespace gs
