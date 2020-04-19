// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/Test.h"
#include "Game.h"
#include "System/Window.h"

#include <iostream>

using namespace engine;

TestCommand::TestCommand(Game* game, Key key, State state) : Command(game), mKey(key), mState(state) {}

void TestCommand::execute() {
	if (mGame->getWindowSystem()->isKey(mKey, mState)) {
		std::cout << "TestCommand execute!" << std::endl;
	}
}
