// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/PlayerOverviewStart.h"
#include "Game.h"
#include "System/Render.h"
#include "System/Window.h"

namespace engine {

PlayerOverviewStartCommand::PlayerOverviewStartCommand(Game* game, Button button, State state)
		: Command(game)
		, mButton(button)
		, mState(state) {}

PlayerOverviewStartCommand::~PlayerOverviewStartCommand() {}

void PlayerOverviewStartCommand::execute() {
	if (mGame->getWindowSystem()->isMouseButton(mButton, mState)) {
		mGame->getRenderSystem()->camera(RenderSystem::CameraType::Orbit);
	}
}

} // namespace engine
