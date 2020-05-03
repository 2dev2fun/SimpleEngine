// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"
#include "System/Input/Key.h"
#include "System/Input/State.h"

namespace engine {

class PlayerRightCommand : public Command {
public:
	PlayerRightCommand(Game* game, Key key, State state);
	~PlayerRightCommand();

	void execute() override;
private:
	Key   mKey;
	State mState;
};

} // namespace engine
