// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

namespace engine {

class Game;

class Command {
public:
	Command(Game* game);
	virtual ~Command() = default;

	virtual void execute() = 0;
protected:
	Game* mGame;
};

} // namespace engine
