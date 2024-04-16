#include "RoomCellsView.h"

void RoomCellsView::event(Room& room) {
	system("cls");
	Cell*** cells = room.getCells();
	for (int i = 0; i < room.getHigh(); i++) {
		for (int j = 0; j < room.getWide(); j++) {
			cells[i][j]->visit(out);
		}
		out << endl;
	}
}