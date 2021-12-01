// Map class implementation
// By Nick Verrochi
// Last Modified: 3/13/15

#include "Map.h"
using namespace std;

Map::Map() {
	;
}

Map::Map(int xSize, int ySize, MapPoint start) {
	setXMax(xSize);
	setYMax(ySize);
	setLocation(start);
}

void Map::setXMax(int x) {
	if (x < 1) { // makes sure xMax is positive
		x = 1; 
	}
	xMax = x;
}

void Map::setYMax(int y) {
	if (y < 1) {
		y = 1;
	}
	yMax = y;
}

void Map::setLocation(MapPoint loc) {
	// makes sure location is in bounds
	if (loc.x >= xMax) {
		loc.x = 0; 
	}
	if (loc.y >= yMax) {
		loc.y = 0;
	}
	location = { loc.x, loc.y };
}

void Map::setLocation(int x, int y) {
	if (x >= xMax) {
		x = 0;
	}
	if (y >= yMax) {
		y = 0;
	}
	location = { x, y };
}

int Map::getXMax() const {
	return xMax;
}

int Map::getYMax() const {
	return yMax;
}

MapPoint Map::getLocation() const {
	return location;
}

Direction Map::getLastMove() const {
	return lastMove;
}

bool Map::navUp() {
	// bounds check
	if (location.y + 1 >= yMax) {
		return false;
	}
	else {
		++location.y;
		lastMove = UP;
		return true;
	}
}

bool Map::navDown() {
	if (location.y - 1 < 0) {
		return false;
	}
	else {
		--location.y;
		lastMove = DOWN;
		return true;
	}
}

bool Map::navLeft() {
	if (location.x - 1 < 0) {
		return false;
	}
	else {
		--location.x;
		lastMove = LEFT;
		return true;
	}
}

bool Map::navRight() {
	if (location.x + 1 >= xMax) {
		return false;
	}
	else {
		++location.x;
		lastMove = RIGHT;
		return true;
	}
}

void Map::reverseMove() {
	switch (lastMove) {
		case UP:
			navDown();
			break;
		case DOWN:
			navUp();
			break;
		case LEFT:
			navRight();
			break;
		case RIGHT:
			navLeft();
	}
}