#pragma once
#include <iostream>
#include "IObserver.h"

using namespace std;

class Player;

class IPlayerView : public IObserver<Player> {
protected:
	ostream& out;
public:
	IPlayerView(ostream& _out): out(_out) {}
	virtual void event(Player& player) =0;
};