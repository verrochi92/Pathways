// Map class, used for handling navigation and map display
// doesn't contain the squares but is used for display and reference
// By Nick Verrochi
// Last Modified: 3/17/15

#ifndef MAP_H
#define MAP_H

#include <iostream>
using namespace std;

// structure for holding an (x, y) coordinate
// used for returning location on the game map
struct MapPoint {
	int x;
	int y;
};

// enumerated type for directions to keep track of last move
enum Direction { UP, DOWN, LEFT, RIGHT };

class Map {

public:
	// constructors
	Map(); // default constructor, sets map to a 1 X 1 grid 
	Map(int, int, MapPoint); // sets xMax, yMax, and start point

	// mutators
	void setXMax(int); // width of the map
	void setYMax(int); // height of the map
	void setLocation(MapPoint); // set location with MapPoint structure
	void setLocation(int, int); // set location with x and y

	// accessors
	int getXMax() const;
	int getYMax() const;
	MapPoint getLocation() const;
	Direction getLastMove() const;

	// navigation functions
	bool navUp();
	bool navDown();
	bool navLeft();
	bool navRight();
	// these will all keep the player within bounds and on the path
	// returns boolean if move within bounds
	void reverseMove();
	// reverses last move (used when a bad square is stepped on)

private:
	int xMax, yMax;  
	MapPoint location;
	Direction lastMove;
};

#endif