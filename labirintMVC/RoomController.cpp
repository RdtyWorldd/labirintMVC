#include "RoomController.h"

void RoomController::addPlayer(int x, int y, Player& player) {
	Cell*** cells = room.getCells();

	int ox = player.getX();
	int oy = player.getY();

	Cell* t = cells[y][x];
	cells[y][x] = *t + player;
	delete t;

	t = cells[oy][ox];
	cells[oy][ox] = *t - player;
	delete t;
}

void RoomController::show()
{
	room.show();
}
