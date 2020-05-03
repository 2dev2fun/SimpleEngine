// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"
#include "System/Input/Button.h"
#include "System/Input/State.h"

#include <memory>

namespace engine {

class PlayerOverviewStartCommand : public Command {
public:
	PlayerOverviewStartCommand(Game* game, Button button, State state);
	~PlayerOverviewStartCommand();

	void execute() override;
private:
	Button mButton;
	State  mState;
	std::shared_ptr<Camera> mCamera;
};

} // namespace engine
