// File: shared_texture_holder.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2019 Murilo Bento
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

#ifndef GS_SHARED_TEXTURE_HOLDER_HPP
#define GS_SHARED_TEXTURE_HOLDER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>

namespace gs {

class SharedTextureHolder {
private:
  std::map<std::string, std::weak_ptr<sf::Texture>> holder;

public:
  std::shared_ptr<sf::Texture> load(const std::string &path);
};

} // namespace gs

#endif
