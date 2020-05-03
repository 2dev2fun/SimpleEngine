// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"
#include "System/Input/Key.h"
#include "System/Input/State.h"

namespace engine {

class PlayerLeftCommand : public Command {
public:
	PlayerLeftCommand(Game* game, Key key, State state);
	~PlayerLeftCommand();

	void execute() override;
private:
	Key   mKey;
	State mState;
};

} // namespace engine
