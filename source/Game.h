// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Game/State.h"

#include <memory>

namespace engine {

class WindowSystem;

class Game {
public:
	Game();
	~Game();

	void loop();

	void setState(game::State state);
	game::State getState() const;

	WindowSystem* getWindowSystem();
private:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	game::State mState;

	std::unique_ptr<WindowSystem> mWindowSystem;
};

inline void Game::setState(game::State state) {
	mState = state;
}

inline game::State Game::getState() const {
	return mState;
}

inline WindowSystem* Game::getWindowSystem() {
	return mWindowSystem.get();
}

} // namespace engine
