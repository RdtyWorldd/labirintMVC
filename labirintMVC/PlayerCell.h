#pragma once

#include "Cell.h"
#include "Player.h"

#include "ClearCell.h"

class PlayerCell : public Cell {
	Player* player;
public:
	PlayerCell(Player* _player) :player(_player) {}

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	void visit(ostream& out);
	Cell* copy();
};