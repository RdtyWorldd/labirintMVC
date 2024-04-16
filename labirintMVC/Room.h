#pragma once
#include "vector"

#include "Cell.h"
#include "ClearCell.h"
#include "PlayerCell.h"
#include "Wall.h"
#include "Treasure.h"
#include "Exit.h"

#include "Monster.h"

#include "IRoomView.h"

class Room {
	int id;
	int high, wide;
	Cell*** cells;

	int monstersCount;
	Monster** monsters;

	vector<IRoomView*> allObservers;

	void event();
public:
	Room();
	Room(const Room& room);
	Room& operator = (const Room & room);
	~Room();
	void addObserver(IRoomView* o);

	int getId();
	int getHigh();
	int getWide();
	Cell*** getCells();

	int getMonstersCount();
	Monster** getMonsters();

	void show();

	friend istream& operator >>(istream& in, Room& room);
};

istream& operator >>(istream& in, Cell*& cell);