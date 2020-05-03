// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Command.h"
#include "Engine.h"

namespace engine {

class PlayerRotationCommand : public Command {
public:
	PlayerRotationCommand(Game* game);
	~PlayerRotationCommand();

	void execute() override;
};

} // namespace engine
