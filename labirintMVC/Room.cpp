#include "Room.h"

Room::Room() : high(0), wide(0), cells(nullptr), monstersCount(0), monsters(nullptr) {}

Room::Room(const Room& room) {
	high = room.high;
	wide = room.wide;
	if (room.cells == nullptr) {
		cells = nullptr;
		return;
	}

	cells = new Cell * *[high];
	for (size_t i = 0; i < high; i++) {
		cells[i] = new Cell * [wide];
		for (size_t j = 0; j < wide; j++) {
			cells[i][j] = room.cells[i][j]->copy();
		}
	}

	monstersCount = 0;
	monsters = nullptr;

	if (room.monstersCount > 0) {
		monstersCount = room.monstersCount;
		monsters = new Monster * [monstersCount];

		for (int i = 0; i < monstersCount; i++) {
			//monsters[i] = room.monsters[i]->copy();
		}
	}
}

Room& Room::operator =(const Room& room) {
	if (this == &room)
		return *this;

	high = room.high;
	wide = room.wide;

	if (cells != nullptr) {
		for (int i = 0; i < high; i++) {
			for (int j = 0; j < wide; j++) {
				delete cells[i][j];
			}
			delete cells[i];
		}
		delete[] cells;
	}

	if (room.cells == nullptr) {
		cells = nullptr;
		return *this;
	}

	cells = new Cell * *[high];
	for (size_t i = 0; i < high; i++) {
		cells[i] = new Cell * [wide];
		for (size_t j = 0; j < wide; j++) {
			cells[i][j] = room.cells[i][j]->copy();
		}
	}

	if (monstersCount > 0) {
		for (int i = 0; i < monstersCount; i++) {
			delete monsters[i];
		}
		delete monsters;
	}

	if (room.monsters == nullptr) {
		monsters = nullptr;
		return *this;
	}

	monstersCount = room.monstersCount;
	for (int i = 0; i < monstersCount; i++) {
		//monsters[i] = room.monsters[i]->copy();
	}
	return *this;
}

Room::~Room() {
	if (cells != nullptr) {
		for (int i = 0; i < high; i++) {
			for (int j = 0; j < wide; j++) {
				delete cells[i][j];
			}
			delete cells[i];
		}
		delete[] cells;
	}
}

void Room::addObserver(IRoomView* o) {
	allObservers.push_back(o);
}

int Room::getHigh() { return high; }
int Room::getWide() { return wide; }
Cell*** Room::getCells() { return cells; }

int Room::getMonstersCount() { return monstersCount; }
Monster** Room::getMonsters() { return monsters; }

void Room::event() {
	for (IRoomView* o : allObservers) {
		o->event(*this);
	}
}

void Room::show() {
	event();
}

istream& operator >>(istream& in, Room& room) {
	int high = 0;
	int wide = 0;

	in >> high >> wide;
	if (high < 3 || wide < 3) {
		throw invalid_argument("room can't be less than: high = 3, wide = 3");
		return in;
	}
	room.high = high;
	room.wide = wide;

	room.cells = new Cell * *[high];
	for (int i = 0; i < high; i++) {
		room.cells[i] = new Cell * [wide];
		for (int j = 0; j < wide; j++) {
			in >> room.cells[i][j];
		}
	}

	int monstersCount = 0;
	in >> monstersCount;

	if (monstersCount > 0) {
		room.monstersCount = monstersCount;
		room.monsters = new Monster* [monstersCount];
		for (int i = 0; i < monstersCount; i++) {
			//in >> room.monstrers[i];
		}
	}
	
	return in;
}

istream& operator >>(istream& in, Cell*& cell) {
	unsigned char tmp;

	in >> tmp;
	switch (tmp)
	{
	case '_':
		cell = new ClearCell();
		break;
	case '#':
		cell = new Wall();
		break;
	case '$':
		cell = new Treasure();
		break;
	case '/':
		int nextRoom = 0;
		in >> nextRoom;
		cell = new Exit(nextRoom);
		break;
	}

	return in;
}
