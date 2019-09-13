#include "gs2d/other/helpers/resource_manager.hpp"

namespace gs {

const sf::Texture &ResourceManager::load(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
    if (!resource->loadFromFile(path))
      throw std::runtime_error("ResourceManager error - Couldn't open file " +
                               path + ".");

    resources.insert(std::make_pair(path, resource));
    return *resources.at(path).get();
  } else {
    return *it->second;
  }
}

sf::Texture *ResourceManager::load_ptr(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    std::shared_ptr<sf::Texture> resource = std::make_shared<sf::Texture>();
    if (!resource->loadFromFile(path))
      throw std::runtime_error("ResourceManager error - Couldn't open file " +
                               path + ".");

    resources.insert(std::make_pair(path, resource));
    return resources.at(path).get();
  } else {
    return it->second.get();
  }
}

std::shared_ptr<sf::Texture> ResourceManager::get(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      resources.find(path);
  if (it == resources.end()) {
    throw std::runtime_error("ResourceManager error - No entry on map for " +
                             path + ".");
  } else {
    return it->second;
  }
}

bool ResourceManager::has_texture(const std::string &path) {
  if (resources.find(path) == resources.end())
    return false;
  else
    return true;
}

void ResourceManager::set_texture(const std::string &path,
                                  std::shared_ptr<sf::Texture> resource) {
  resources.insert(std::make_pair(path, resource));
}

} // namespace gs
