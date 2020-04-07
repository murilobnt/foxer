// File: local_texture_repository.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_LOCAL_TEXTURE_REPOSITORY_HPP_
#define FOX_LOCAL_TEXTURE_REPOSITORY_HPP_

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

#include "foxer/logical/shared_texture_repository.hpp"

namespace fox {

// Local repository of textures. It uses a SharedTextureRepository to load textures,
// and it keeps the references to a local map. As soon as all references to
// a texture are gone, the texture is deleted (because no one is using it).

class LocalTextureRepository {
public:

  // Empty constructor.
  LocalTextureRepository();

  // Constructor. Receives a reference to the stex_repo (usually from the
  // scene).
  explicit LocalTextureRepository(SharedTextureRepository *stex_repo);

  // Load a texture and return a texture (or a reference to it).
  const sf::Texture &load(const std::string &path, bool smooth = false,
                                    bool repeated = false);
  sf::Texture *load_ptr(const std::string &path, bool smooth = false,
                                    bool repeated = false);

private:

  // A reference to the shared holder.
  SharedTextureRepository *stex_repo;

  // The map containing all loaded textures from the local repository.
  std::map<std::string, std::shared_ptr<sf::Texture>> textures;
};

} // namespace fox

#endif
