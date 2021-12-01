// Abstract Function Implementation
// By Nick Verrochi
// Last Modified: 3/25/15

#include "Functions.h"
using namespace std;

void printInputMenu() {
	cout << endl << "Choose a direction: \n"
		<< "\t 1. Up \n"
		<< "\t 2. Down \n"
		<< "\t 3. Left \n"
		<< "\t 4. Right \n\n";
}

double getNum() {
	double num;
	while (!(cin >> num)) { // checks if non-numeric
		cout << "Numbers only! Try again: ";
		cin.clear();   cin.ignore(80, '\n');
	}
	cin.ignore(80, '\n');
	return num;
}

int getInt() {
	double num = getNum();
	while (num != static_cast<int>(num)) { // checks if integer
		cout << "Whole numbers only! Try again: ";
		num = getNum();
	}
	return static_cast<int>(num);
}

int getMenuChoice(int min, int max) {
	int menuChoice = getInt();
	while (menuChoice < min || menuChoice > max) {
		cout << "You must enter a number between " << min << " and " << max
			<< "! Try again: ";
		menuChoice = getInt();
	}
	return menuChoice;
}

bool navSuccessful(Map &map, int menuChoice) {
	switch (menuChoice) {
	case 1:
		return map.navUp();
	case 2:
		return map.navDown();
	case 3:
		return map.navLeft();
	case 4:
		return map.navRight();
	default:
		return false; // ensures return
	}
}

void printMap(Square squares[9][6], MapPoint location, bool mapMode) {
	cout << "\t _ _ _ _ _ _ _ _ _ \n";
	for (int y = 5; y >= 0; --y) {
		cout << "\t";
		for (int x = 0; x < 9; ++x) {
			// prints an 'x' to mark a pressed square
			// or an already mapped square in map mode
			cout << "|";
			// marks current position with '.'
			if (location.x == x && location.y == y) {
				cout << ".";
			}
			// marks squares already pressed or mapped with 'x'
			else if (mapMode && squares[x][y].getStatus() == PATH
				|| !mapMode && squares[x][y].getStatus() == PRESSED) {
				cout << "x";
			}
			else {
				cout << " ";
			}
		}
		cout << "|" << endl << "\t - - - - - - - - - \n";
	}
}

void printErrors(Square squares[9][6]) {
	const int SIZE = 54; 
	int numErrorsInOrder[SIZE];
	MapPoint locations[SIZE]; // parallel with numErrorsInOrder
	int i = 0;

	// get error amounts and locations
	for (int x = 0; x < 9; ++x) {
		for (int y = 0; y < 6; ++y, ++i) {
			numErrorsInOrder[i] = squares[x][y].getLocalErrors();
			locations[i].x = x;
			locations[i].y = y;
		}
	}

	// sort errors and locations
	doubleSort(numErrorsInOrder, locations, SIZE);

	// print back from greatest - least
	cout << "You made " << Square::getGlobalErrors() << " total errors.\n";
	for (i = 0; numErrorsInOrder[i] > 0; ++i) {
		cout << "(" << locations[i].x << ", " << locations[i].y << "): " << numErrorsInOrder[i] << " errors. \n";
	}
}

void doubleSort(int numErrors[], MapPoint locations[], const int SIZE) {
	bool swapped;

	do {
		for (int i = 0, swapped = false; i < SIZE - 1; ++i) {
			if (numErrors[i] < numErrors[i + 1]) {
				intSwap(numErrors[i], numErrors[i + 1]);
				pointSwap(locations[i], locations[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}

void intSwap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void pointSwap(MapPoint &point1, MapPoint &point2) {
	MapPoint temp = { point1.x, point1.y };
	point1 = { point2.x, point2.y };
	point2 = { temp.x, temp.y };
}