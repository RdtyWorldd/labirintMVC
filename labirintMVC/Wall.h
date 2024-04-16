#pragma once

#include "Cell.h"

class Wall : public Cell {
public:
	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	void visit(ostream& out);
	Cell* copy();
};