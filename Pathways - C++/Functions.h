// Abstract functions for pathway game
// By Nick Verrochi
// Last Modified: 3/25/15

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Map.h"
#include "Square.h"
using namespace std;

void printInputMenu();
// prints a menu to get a direction to move in

double getNum();
// gets a numerical value from cin

int getInt();
// takes a double from input, checks if it is an integer, than casts and returns it
// this is to avoid truncation of any decimals entered and produce a message

int getMenuChoice(int, int);
// gets a valid integer as a menu choice between min and max, inclusive

bool navSuccessful(Map &, int);
// attempts to navigate based on menu choice, if the move will bring the payer out of bounds,
// location will not change, otherwise the move will be made

void printMap(Square [9][6], MapPoint, bool = false);
// prints a map, this function is abstract due to the need to access
// the status of a 6 X 9 two-dimensional array of square objects
// and can not print a map of a different size than the array of squares
// prints an 'x' where squares are already mapped (in mapping mode), or already pressed (during game)
// the MapPoint parameter is for location, the mapMode indicates mapping mode
// will enter in game mode by defaule

void printErrors(Square [9][6]);
// finds the number of errors in each square
// and displays them in order from most to least errors, along with their x, y location
// if there are none, the square will not be displayed

void doubleSort(int [], MapPoint [], int);
// sorts an array of integers from greatest to smallest
// also swaps elements of the MapPoint array to keep it parallel

void intSwap(int &, int &);
// swaps two integer values

void pointSwap(MapPoint &, MapPoint &);
// swaps the x and y values of two MapPoints

#endif