#pragma once
#include <vector>

#include "Moveable.h"
#include "IPlayerView.h"

class Player : public Moveable {
	int treasures;
	int steps;

	vector<IPlayerView*> allObservers;
	void event() {
		for (IPlayerView* view : allObservers)
			view->event(*this);
	}
public:
	Player(int x = 1, int y = 1, int hp = 1) :Moveable(x, y, hp), treasures(0), steps(0) {}
	
	void addObserver(IPlayerView* o) { allObservers.push_back(o); }

	int getTreasures() { return treasures; }
	void addTreasures() { treasures++; event(); }
	int getSteps() { return steps; }

	void move(int x, int y) { 
		Moveable::move(x, y);
		steps++;
		event();
	}
	void show() {
		event();
	}
};