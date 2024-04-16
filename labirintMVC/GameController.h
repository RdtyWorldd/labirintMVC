#pragma once
#include <conio.h>

#include "Game.h"

class GameController {
	Game& game;
public:
	GameController(Game& _game): game(_game) {}
	void run();
};