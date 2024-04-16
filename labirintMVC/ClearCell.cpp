#include "ClearCell.h"

void ClearCell::visit(ostream& out) { out << " "; }

void ClearCell::fileCopy(ostream& out) { out << '_'; }

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