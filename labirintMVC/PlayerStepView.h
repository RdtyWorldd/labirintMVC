#pragma once

#pragma once

#include "IPlayerView.h"
#include "Player.h"

class PlayerStepView : public IPlayerView {
public:
	PlayerStepView(ostream& out) : IPlayerView(out) {}

	void event(Player& player) {
		out << player.getSteps()<< endl;
	}
};