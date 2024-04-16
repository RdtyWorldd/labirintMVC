#include <iostream>
#include <fstream>

#include "RoomCellsView.h"
#include "Room.h"

#include "Player.h"
#include "PlayerStatView.h"
#include "PlayerStepView.h"

#include "Game.h"
#include "GameController.h"

using namespace std;

int main() {
	Room room;
	{
		ifstream f("data\\rooms\\room1.txt");
		f >> room;
	}

	IRoomView* view = new RoomCellsView(cout);
	room.addObserver(view);

	//room.show();

	Player p;
	IPlayerView* stat = new PlayerStatView(cout);
	IPlayerView* steps = new PlayerStepView(cout);

	p.addObserver(stat);
	p.addObserver(steps);

	//p.move(2, 2);
	//system("cls");
	//p.addTreasures();

	Game game(p, room);
	GameController controller(game);
	controller.run();
}