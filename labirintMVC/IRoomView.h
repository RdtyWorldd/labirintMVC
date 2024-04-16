#pragma once
#include <iostream>

#include "IObserver.h"

class Room;

using namespace std;

class IRoomView : public IObserver <Room> {
protected:
	ostream& out;
public:
	IRoomView(ostream& _out) :out(_out) {}
	virtual void event(Room& model) = 0;
};