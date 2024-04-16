#pragma once

#include "IPlayerView.h"
#include "Player.h"

class PlayerStatView : public IPlayerView {
public:
	PlayerStatView(ostream& out) : IPlayerView(out) {}

	void event(Player& player) {
		out << "Hp: " << player.getHP() << " | Treasures: " << player.getTreasures() << endl;
	}
};