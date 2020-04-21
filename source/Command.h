// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

class Command {
public:
	Command(Game* game);
	virtual ~Command() = default;

	virtual void execute() = 0;
protected:
	Game* mGame;
};

} // namespace engine
