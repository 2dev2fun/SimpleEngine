// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Game/State.h"

#include <memory>

namespace engine {

class Game {
public:
	Game();
	~Game();

	void loop();

	void setState(GameState state);
	GameState getState() const;

	InputSystem* getInputSystem();
	WindowSystem* getWindowSystem();
private:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	GameState mGameState;

	std::unique_ptr<InputSystem> mInputSystem;
	std::unique_ptr<WindowSystem> mWindowSystem;
};

inline void Game::setState(GameState gameState) {
	mGameState = gameState;
}

inline GameState Game::getState() const {
	return mGameState;
}

inline InputSystem* Game::getInputSystem() {
	return mInputSystem.get();
}

inline WindowSystem* Game::getWindowSystem() {
	return mWindowSystem.get();
}

} // namespace engine
