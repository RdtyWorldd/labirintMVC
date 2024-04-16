#pragma once
#include "Moveable.h"

class Monster : public Moveable {
	int strartX, startY;
public:
	Monster(int x = 1, int y = 1, int hp = 1):Moveable(x ,y , hp), startY(y), strartX(x) {}
	virtual void move(int x = -1, int y = -1) = 0;
	virtual ~Monster();
};