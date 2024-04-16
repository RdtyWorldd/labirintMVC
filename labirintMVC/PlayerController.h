#pragma once

#include "Player.h"

class PlayerController {
	Player& player;
public:
	PlayerController(Player& _player): player(_player) {}
	void move(int x, int y);
	void show();
};