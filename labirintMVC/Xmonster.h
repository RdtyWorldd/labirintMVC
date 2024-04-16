#pragma once
#include "Monster.h"

class Xmonster : public Monster {
public:
	Xmonster(int x = 1, int y = 1, int hp = 1) :Monster(x, y, hp) {}
};