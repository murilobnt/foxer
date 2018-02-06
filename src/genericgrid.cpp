#include "gamesimple/assist/genericgrid.hpp"

GenericGrid::GenericGrid(){}

GenericGrid::GenericGrid(int w, int h, int unitySize){
	this->w = w;
	this->h = h;

	this->xCells = ceil((float)w / unitySize);
	this->yCells = ceil((float)h / unitySize);

	this->unitySize = unitySize;
}
