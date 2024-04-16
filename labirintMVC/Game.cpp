#include "Game.h"
#include "RoomDao.h"

Game::Game(Player* _player, Room* _room) {
	room = new Room(*_room);
	player = new Player(*_player);

	int x = player->getX();
	int y = player->getY();
	Cell* t = room->getCells()[y][x];
	room->getCells()[y][x] = new PlayerCell(player);
	delete t;
}

Game::Game(const Game& game) {
	room = new Room(*game.room);
	player = new Player(*game.player);
}

Game::~Game() {
	delete room;
	delete player;
}

void Game::move(Action act) {
	int x = player->getX();
	int y = player->getY();

	switch (act) {
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	}

	if ((x < 0) || (y < 0) || (x >= room->getWide()) || (y >= room->getHigh())) {
		return;
	}
	else {
		try {
			//room controller
			RoomController roomController(*room);
			roomController.addPlayer(x, y, *player);
		}
		catch (ExitException e) {
			changeRoom(e.getNextRoom()); 
		}
		catch (AddCellException e) {
			room->show();
			player->move(player->getX(), player->getY());
			//cout <<e.what();
		}
	}
}

Room* Game::getRoom() {
	return room;
}

Player* Game::getPlayer() {
	return player;
}

void Game::changeRoom(int roomId) {
	RoomDao dao;
	
	int ox = player->getX();
	int oy = player->getY();

	Cell*** cells = room->getCells();
	delete cells[oy][ox];
	cells[oy][ox] = new ClearCell();
	dao.updateRoom(*room);
	delete room;

	room = dao.getRoom(roomId);
	room->addObserver(new RoomCellsView(cout));

	int x = (room->getWide() - 1) / 2;
	int y = (room->getHigh() - 1) / 2;

	cells = room->getCells();
	delete cells[y][x];
	cells[y][x] = new PlayerCell(player);

	room->show();
	player->move(x, y);
}