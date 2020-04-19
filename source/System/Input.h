// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Window.h"

#include <memory>
#include <vector>

namespace engine {

class Command;
class Game;

class InputSystem {
public:
	InputSystem(Game* game);
	~InputSystem();

	void update();

	void attachCommand(std::shared_ptr<Command> command);
	void detachCommand(std::shared_ptr<Command> command);
private:
	Game* mGame;
	std::vector<std::shared_ptr<Command>> mCommands;
};

} // namespace engine
