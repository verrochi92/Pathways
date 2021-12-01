// Square class header
// By Nick Verrochi
// Last Modified: 3/15/15

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

enum Status { UNTOUCHED , WARNING , PATH, PRESSED };
// this enumerated type is used rather than a set of booleans

class Square {

public:
	Square(); // constructor, defaults members

	// mutators
	void setStatus(Status);
	void setLocalErrors(int);

	// accessors
	Status getStatus() const; 
	int getLocalErrors() const; // number of errors counted in square 
	static int getGlobalErrors(); // global errors

	// status related functions
	void map();
	// this function maps a square as part of the path
	// changing its status to "PATH" 
	
	void reset();
	// this function will reset a squares status to "UNTOUCHED"
	// this will remove it from the path

	// input handling functions
	void press(); 
	// this function will take the input from the square and 
	// decide what to do based on the status of the square

	void warn();
	// if the square is not part of the path, a warning is given
	// error is not counted but status is changed

	void error();
	// for squares already warned about, but stepped on again
	// this function will update error counts

private:
	int localErrors;
	static int globalErrors;
	Status squareStatus;
};

#endif