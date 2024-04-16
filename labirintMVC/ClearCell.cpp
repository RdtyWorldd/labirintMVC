#include "ClearCell.h"

void ClearCell::visit(ostream& out) {
	out << " ";
}

Cell* ClearCell::copy() {
	return new ClearCell();
}

Cell* ClearCell::operator+ (Player& player) {
	return new PlayerCell(&player);
}

Cell* ClearCell::operator- (Player& player) {
	throw AddCellException();
	return new ClearCell();
}