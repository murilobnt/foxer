#include "gs2d_engine/other/helpers/texture_loader.hpp"

namespace gs {

void TextureLoader::load_texture(sf::Texture &texture,std::string path) {
        if (!texture.loadFromFile(path)) {
                // Error. Still need to do something if this occurs.
        }
}

void TextureLoader::create_texture(sf::Texture &texture, int w, int h) {
        if (!texture.create(w, h)) {
                // Error. Still need to do something if this occurs.
        }
}

void TextureLoader::set_texture_from_file(sf::Texture &texture_to_be_loaded,
                                          std::string path,
                                          int w, int h,
                                          bool is_repeated, bool has_bitmask) {
        if (!has_bitmask)
                load_texture(texture_to_be_loaded, path);
        else
                Collision::CreateTextureAndBitmask(texture_to_be_loaded,
                                                   path);

        create_texture(texture_to_be_loaded, w, h);
        texture_to_be_loaded.setRepeated(is_repeated);
}

}
