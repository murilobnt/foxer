namespace gs {

template <typename Index>
const sf::Texture &ResourceManager<Index>::load(const Index &index, const std::string &path) {
  std::unique_ptr<sf::Texture> resource(new sf::Texture());
  if (!resource->loadFromFile(path))
    throw std::runtime_error("ResourceManager error - Couldn't open file " +
                             path + ".");

  resources.insert(std::make_pair(index, std::move(resource)));
  return *resources.at(index);
}

template <typename Index>
const sf::Texture &ResourceManager<Index>::get(const Index &index) const {
  typename std::map<Index, std::unique_ptr<sf::Texture>>::const_iterator it =
      resources.find(index);
  if (it == resources.end())
    throw std::runtime_error(
        "ResourceManager error - Couldn't retrieve the resource.");
  return *it->second;
}

} // namespace gs
