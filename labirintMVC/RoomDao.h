#pragma once
#include "Room.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class RoomDao {
	string dataPath = "data\\rooms\\room";
public:
	Room* getRoom(int id);
	void updateRoom(Room& room);
};