#pragma once
#include "IRoomView.h"
#include "Room.h"

class RoomCellsView : public IRoomView {
public:
	RoomCellsView(ostream& out) : IRoomView(out) {}
	void event(Room& room);
};