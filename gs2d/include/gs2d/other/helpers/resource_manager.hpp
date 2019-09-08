#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

namespace gs {
template <typename Index> class ResourceManager {
private:
  std::map<Index, std::unique_ptr<sf::Texture>> resources;

public:
  const sf::Texture &load(const Index &index, const std::string &path);
  const sf::Texture &get(const Index &index) const;
};
} // namespace gs

#include "gs2d/other/helpers/resource_manager.inl"

#endif
