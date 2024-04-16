#include "Exit.h"

Exit::Exit(int _nextRoom) : nextRoom(_nextRoom) {}

void Exit::visit(ostream& out) {
	out << "/";
}

Cell* Exit::copy() {
	return new Exit(nextRoom);
}

Cell* Exit::operator + (Player& player) {
	throw ExitException(nextRoom);
	return new Exit(nextRoom);
}

Cell* Exit::operator -(Player& player) {
	throw AddCellException();
	new Exit(nextRoom);
}