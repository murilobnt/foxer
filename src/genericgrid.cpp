#include "gamesimple/assist/genericgrid.hpp"

GenericGrid::GenericGrid(){
}

GenericGrid::GenericGrid(int w, int h, int unitySize) {
	this->w = w;
	this->h = h;
	this->unitySize = unitySize;

	xCells = ceil((float)w / unitySize);
	yCells = ceil((float)h / unitySize);
}
