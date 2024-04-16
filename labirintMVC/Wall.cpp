#include "Wall.h"

void Wall::visit(ostream& out) {
	out << "#";
}

Cell* Wall::copy() {
	return new Wall();
}

Cell* Wall::operator +(Player& player) {
	throw AddCellException();
	return new Wall();
}

Cell* Wall::operator -(Player& player) {
	throw AddCellException();
	return new Wall();
}
