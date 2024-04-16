#include "PlayerCell.h"

void PlayerCell::visit(ostream& out) {
	out << "@";
}
Cell* PlayerCell::copy() {
	return new PlayerCell(player);
}

Cell* PlayerCell::operator+(Player& player) {
	throw AddCellException();
	return new PlayerCell(this->player);
}

Cell* PlayerCell::operator-(Player& player) {
	return new ClearCell();
}