#pragma once

enum Action {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Moveable {
protected:
	int x, y;
	int hp;

public:
	Moveable(int _x = 1, int _y = 1, int _hp = 1) : x(_x), y(_y), hp(_hp) {}
	int getX() { return x; }
	int getY() { return y; }
	int getHP() { return hp; }
	virtual void move(int _x, int _y) { x = _x; y = _y; }
	virtual ~Moveable() {}
};