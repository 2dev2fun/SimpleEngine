// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/PlayerRight.h"
#include "Component/Move.h"
#include "Game.h"
#include "System/Window.h"
#include "System/World.h"

namespace engine {

PlayerRightCommand::PlayerRightCommand(Game* game, Key key, State state)
		: Command(game)
		, mKey(key)
		, mState(state) {}

PlayerRightCommand::~PlayerRightCommand() {}

void PlayerRightCommand::execute() {
	if (mGame->getWindowSystem()->isKey(mKey, mState)) {
		auto worldSystem = mGame->getWorldSystem();
		auto player = worldSystem->getPlayer();

		auto* moveComponent = worldSystem->getMoveComponent(player);
		moveComponent->setStrafeValue(moveComponent->getStrafeValue() + moveComponent->getStrafeSpeed());
	}
}

} // namespace engine

