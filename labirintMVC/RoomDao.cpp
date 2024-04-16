#include "RoomDao.h"

Room* RoomDao::getRoom(int id) {
	string path = dataPath + to_string(id) + ".txt";
	{
		ifstream file(path);
		Room room;
		file >> room;
		return new Room(room);
	}
	throw std::exception();
	return nullptr;
}

void RoomDao::updateRoom(Room& room) {
	string path = dataPath + to_string(room.getId()) + ".txt";
	{
		ofstream file(path);
		file << room.getId() << endl;
		file << room.getHigh() <<' '<< room.getWide() << endl;
		
		Cell*** cells = room.getCells();
		for (int i = 0; i < room.getHigh(); i++) {
			for (int j = 0; j < room.getWide(); j++) {
				cells[i][j]->fileCopy(file);
			}
			file << endl;
		}
		file << room.getMonstersCount() << endl;

		return;
	}
	throw std::exception();
	return;
}