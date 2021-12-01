// Square class implementation
// By Nick Verrochi
// Last Modified: 3/16/15

#include "Square.h"
using namespace std;

int Square::globalErrors = 0;

Square::Square() {
	setStatus(UNTOUCHED);
	setLocalErrors(0);
}

void Square::setStatus(Status status) {
	squareStatus = status;
}

void Square::setLocalErrors(int num) {
	if (num < 0) { 
		num = 0; // stops from being set negative 
	}
	localErrors = num;
}

Status Square::getStatus() const {
	return squareStatus;
}

int Square::getLocalErrors() const {
	return localErrors;
}

int Square::getGlobalErrors() {
	return globalErrors;
}

void Square::map() {
	squareStatus = PATH;
}

void Square::reset() {
	squareStatus = UNTOUCHED;
}

void Square::press() {
	switch (squareStatus) {
	case UNTOUCHED:
		warn();
		break;
	case WARNING:
		error();
		break;
	case PATH:
		setStatus(PRESSED);
	}
}

void Square::warn() {
	cout << "Warning! Not part of path!\n";
	setStatus(WARNING);
}

void Square::error() {
	cout << "You already made this mistake! Error count updated...\n";
	++localErrors;
	++globalErrors;
}

