// Pathway Game Windows Mock-up
// By Nick Verrochi
// Last Modified: 3/25/15

#include "Functions.h"
using namespace std;

int main() {
	const int PATH_SQUARES = 25;
	const int X_MAX = 9;
	const int Y_MAX = 6;
	const MapPoint START = { 0, 2 };

	int menuChoice;
	MapPoint location = START;
	int numSquares = 0; // goes to 25 when mapping, then counts down during gameplay

	Square squares[X_MAX][Y_MAX]; // create the game squares
	Map *gameMap = new Map(X_MAX, Y_MAX, START); // create game map object

	cout << "First we must map the path. Follow the directions below for input. \n"
		<< "The squares you step on will become part of the path. Once 25 squares have been mapped,"
		<< " the game will begin. \n\n";

	while (numSquares < PATH_SQUARES) {
		// initialize start point
		squares[location.x][location.y].setStatus(PATH);

		printMap(squares, location, true);
		printInputMenu();
		cout << "Choose a direction: ";
		menuChoice = getMenuChoice(1, 4);

		// attempt to navigate		
		while (!navSuccessful(*gameMap, menuChoice)) {
			cout << "Out of bounds! Try again: ";
			menuChoice = getMenuChoice(1, 4);
		}
		// change location and map
		location = gameMap->getLocation();
		// if square not already mapped, map it
		if (squares[location.x][location.y].getStatus() != PATH) {
			squares[location.x][location.y].map();
			++numSquares;
		}
		system("cls");
	}

	cout << "Now it's time to play!!! \n\n";
	system("pause");
	system("cls");

	//reset location
	gameMap->setLocation(START);
	location = gameMap->getLocation();
	squares[location.x][location.y].press();

	while (numSquares > 0) {
		printMap(squares, location);
		printInputMenu();
		cout << "Choose a direction: ";
		menuChoice = getMenuChoice(1, 4);

		while (!navSuccessful(*gameMap, menuChoice)) {
			cout << "Out of bounds! Try again: ";
			menuChoice = getMenuChoice(1, 4);
		}

		location = gameMap->getLocation();
		squares[location.x][location.y].press();
		if (squares[location.x][location.y].getStatus() != PATH &&
			squares[location.x][location.y].getStatus() != PRESSED) {
			gameMap->reverseMove();
			location = gameMap->getLocation();
		}
		else if (squares[location.x][location.y].getStatus() == PRESSED) {
			--numSquares;
		}

		system("cls");
	}

	delete gameMap; 
	system("cls");
	cout << "Congratulations! You have completed the game. \n";
	if (Square::getGlobalErrors() == 0) {
		cout << "You made no mistakes! \n";
	}
	else {
		printErrors(squares);
	}

	system("pause");
	return 0;
}