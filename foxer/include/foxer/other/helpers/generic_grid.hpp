// File: generic_grid.hpp
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

#ifndef FOX_GENERIC_GRID_HPP_
#define FOX_GENERIC_GRID_HPP_

#include <cmath>

namespace fox {

// Represents a grid. Only stores meta values about the grid.

class GenericGrid {
public:
  // Empty constructor.
  GenericGrid();

  // Constructor. Receives a width, height, and the size of what's considered
  // a unity. x_cells then becomes the width divided by the unity_size, and
  // y_cells becomes the height divided by the unity_size. If the division isn't
  // exact, it gets the ceil.
  GenericGrid(int w, int h, int unity_size);

protected:
  // Width, height and the size of an unity of the grid.
  int w;
  int h;
  int unity_size;

  // The number of cells in the X and Y axis of the grid.
  int x_cells;
  int y_cells;
};

} // namespace fox

#endif
