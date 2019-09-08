#include "gs2d/other/helpers/resource_manager.hpp"

namespace gs {

const sf::Texture &ResourceManager::load(const std::string &path) {
  std::map<std::string, std::unique_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    std::unique_ptr<sf::Texture> resource(new sf::Texture);
    if (!resource->loadFromFile(path))
      throw std::runtime_error("ResourceManager error - Couldn't open file " +
                               path + ".");

    resources.insert(std::make_pair(path, std::move(resource)));
    return *resources.at(path);
  } else {
    return *it->second;
  }
}

} // namespace gs
