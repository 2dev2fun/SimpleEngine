// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"
#include "System/Input/Button.h"
#include "System/Input/State.h"

#include <memory>

namespace engine {

class PlayerOverviewStopCommand : public Command {
public:
	PlayerOverviewStopCommand(Game* game, Button button, State state);
	~PlayerOverviewStopCommand();

	void execute() override;
private:
	Button                  mButton;
	State                   mState;
	std::shared_ptr<Camera> mCamera;
};

} // namespace engine
