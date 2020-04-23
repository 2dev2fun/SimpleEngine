// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/Exit.h"
#include "Game.h"
#include "GameState.h"
#include "System/Window.h"

using namespace engine;

ExitCommand::ExitCommand(Game* game, Key key, State state) : Command(game), mKey(key), mState(state) {}

void ExitCommand::execute() {
	if (mGame->getWindowSystem()->isKey(mKey, mState)) {
		mGame->setState(GAME_STATE_EXIT);
	}
}
