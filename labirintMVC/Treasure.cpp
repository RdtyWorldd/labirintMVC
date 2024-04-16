#include "Treasure.h"

void Treasure::visit(ostream& out) {
	out << "$";
}

Cell* Treasure::copy() {
	return new Treasure();
}

Cell* Treasure::operator+ (Player& player) {
	player.addTreasures();
	return new PlayerCell(&player);
}

Cell* Treasure::operator- (Player& player) {
	throw AddCellException();
	return new Treasure();
}