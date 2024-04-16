#pragma once
#include "Room.h"

class RoomController {
	Room& room;
public:
	RoomController(Room& _room) : room(_room) {}
	void addPlayer(int x, int y, Player& player);
	void show();
};