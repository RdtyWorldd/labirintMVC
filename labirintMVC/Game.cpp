#include "Game.h"

Game::Game(Player& _player, Room& _room): player(_player), room(_room) {}
Game::Game(const Game& game): player(game.player), room(game.room) {
	Room tmp = game.room;
	room = tmp;
}

void Game::move(Action act) {
	int x = player.getX();
	int y = player.getY();

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

	if ((x < 0) || (y < 0) || (x >= room.getWide()) || (y >= room.getHigh())) {
		return;
	}
	else {
		try {
			//room controller
			RoomController roomController(room);
			roomController.addPlayer(x, y, player);
		}
		catch (ExitException e) {
			//changeRoom(e.getNextRoom()); 
		}
		catch (AddCellException e) {
			room.show();
			player.move(x, y);
			//cout <<e.what();
		}
	}
}

Room& Game::getRoom() {
	return room;
}

Player& Game::getPlayer() {
	return player;
}