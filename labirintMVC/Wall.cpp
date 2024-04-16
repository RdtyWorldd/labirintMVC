#include "Wall.h"

void Wall::visit(ostream& out) { out << "#"; }
void Wall::fileCopy(ostream& out) { visit(out); }

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
