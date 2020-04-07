#include "foxer/logical/local_texture_repository.hpp"

namespace fox {

LocalTextureRepository::LocalTextureRepository() {}

LocalTextureRepository::LocalTextureRepository
(SharedTextureRepository *stex_repo) {
  this->stex_repo = stex_repo;
}

const sf::Texture &LocalTextureRepository::load(const std::string &path,
                                                bool smooth, bool repeated) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      textures.find(path);

  if (it == textures.end()) {
    std::shared_ptr<sf::Texture> tex = stex_repo->load(path, smooth, repeated);
    textures.insert(std::make_pair(path, tex));
    return *tex;
  } else {
    return *it->second;
  }
}

sf::Texture *LocalTextureRepository::load_ptr(const std::string &path,
                                              bool smooth, bool repeated) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      textures.find(path);

  if (it == textures.end()) {
    std::shared_ptr<sf::Texture> tex = stex_repo->load(path, smooth, repeated);
    textures.insert(std::make_pair(path, tex));
    return tex.get();
  } else {
    return it->second.get();
  }
}

} // namespace fox
