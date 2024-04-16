#include "GameController.h"

void GameController::run() {
	game.getRoom()->show();
	game.getPlayer()->show();
	unsigned char key = 0;
	while (key != 27) {
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		//system("cls");
		switch (key) {
		case 72:
			game.move(UP);
			break;
		case 80:
			game.move(DOWN);
			break;
		case 75:
			game.move(LEFT);
			break;
		case 77:
			game.move(RIGHT);
			break;
		}
	}
}