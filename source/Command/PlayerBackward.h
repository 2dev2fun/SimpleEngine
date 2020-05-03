// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"
#include "System/Input/Key.h"
#include "System/Input/State.h"

namespace engine {

class PlayerBackwardCommand : public Command {
public:
	PlayerBackwardCommand(Game* game, Key key, State state);
	~PlayerBackwardCommand();

	void execute() override;
private:
	Key   mKey;
	State mState;
};

} // namespace engine
