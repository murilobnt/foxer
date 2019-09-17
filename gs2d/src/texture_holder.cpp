#include "gs2d/other/helpers/texture_holder.hpp"

namespace gs {

TextureHolder::TextureHolder() {}

TextureHolder::TextureHolder(SharedTextureHolder *shared_holder) {
  this->shared_holder = shared_holder;
}

const sf::Texture &TextureHolder::load(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      textures.find(path);

  if (it == textures.end()) {
    std::shared_ptr<sf::Texture> tex = shared_holder->load(path);
    textures.insert(std::make_pair(path, tex));
    return *tex;
  } else {
    return *it->second;
  }
}

sf::Texture *TextureHolder::load_ptr(const std::string &path) {
  std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it =
      textures.find(path);

  if (it == textures.end()) {
    std::shared_ptr<sf::Texture> tex = shared_holder->load(path);
    textures.insert(std::make_pair(path, tex));
    return tex.get();
  } else {
    return it->second.get();
  }
}

} // namespace gs
