#pragma once
#include "Cell.h"
#include "PlayerCell.h"

class ClearCell : public Cell {
public:
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);
	void visit(ostream& out);
	Cell* copy();
};