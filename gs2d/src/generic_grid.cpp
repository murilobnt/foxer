#include "gs2d_engine/assist/generic_grid.hpp"

namespace gs {

GenericGrid::GenericGrid(){
}

GenericGrid::GenericGrid(int w, int h, int unity_size) {
	this->w = w;
	this->h = h;
	this->unity_size = unity_size;

	x_cells = ceil((float)w / unity_size);
	y_cells = ceil((float)h / unity_size);
}

}
