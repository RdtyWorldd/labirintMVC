#pragma once

#include "Room.h"
#include "RoomController.h"

#include "Player.h"

class Game {
	//int roomsCount;
	//int roomNow;
	Player& player;
	Room& room;
public:
	Game(Player& player, Room& room);
	//void addPlayer(Player& player);
	Game(const Game& _game);
	Game& operator = (const Game& game);

	Room& getRoom();
	Player& getPlayer();

	//void loadMaze(string file);
	void move(Action act);
	void changeRoom(Room& room);
	//friend ostream& operator <<(ostream& out, const Game& game);
	//friend istream& operator >> (istream& in, Game& game);

	~Game() {};
};