// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/PlayerOverviewStop.h"
#include "Game.h"
#include "System/Render.h"
#include "System/Window.h"

namespace engine {

PlayerOverviewStopCommand::PlayerOverviewStopCommand(Game* game, Button button, State state)
		: Command(game)
		, mButton(button)
		, mState(state) {}

PlayerOverviewStopCommand::~PlayerOverviewStopCommand() {}

void PlayerOverviewStopCommand::execute() {
	if (mGame->getWindowSystem()->isMouseButton(mButton, mState)) {
		mGame->getRenderSystem()->camera(RenderSystem::CameraType::Follow);
	}
}

} // namespace engine
