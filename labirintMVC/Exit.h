#pragma once

#include "Cell.h"
#include "ExitException.h"

class Exit : public Cell {
	int nextRoom;
public:
	Exit(int _nextRoom);

	virtual Cell* operator +(Player& player);
	virtual Cell* operator -(Player& player);

	void visit(ostream& out);
	Cell* copy();
};