#pragma once
#include <iostream>
#include "Player.h"
#include "AddCellException.h"

using namespace std;

class Cell {
public:
	virtual Cell* operator +(Player& player) =0;
	virtual Cell* operator -(Player& player) =0;
	virtual void visit(ostream& out) =0;
	virtual void fileCopy(ostream& out) =0;
	virtual Cell* copy() =0;
	virtual ~Cell() {}
};