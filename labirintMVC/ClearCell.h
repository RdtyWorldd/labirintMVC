#pragma once
#include "Cell.h"
#include "PlayerCell.h"

class ClearCell : public Cell {
public:
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);
	void visit(ostream& out);
	void fileCopy(ostream& out);
	Cell* copy();
};