// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "GameState.h"

#include <memory>
#include <vector>

namespace engine {

class Game {
public:
	Game();
	~Game();

	void loop();

	void setState(GameState state);
	auto getState() const;

	auto getMeshManager();
	auto getTextureManager();

	auto getInputSystem();
	auto getMovementSystem();
	auto getRenderSystem();
	auto getSceneSystem();
	auto getWindowSystem();
	auto getWorldSystem();
private:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	GameState mState;

	std::shared_ptr<MeshManager>    mMeshManager;
	std::shared_ptr<TextureManager> mTextureManager;

	std::shared_ptr<InputSystem>    mInputSystem;
	std::shared_ptr<MovementSystem> mMovementSystem;
	std::shared_ptr<RenderSystem>   mRenderSystem;
	std::shared_ptr<SceneSystem>    mSceneSystem;
	std::shared_ptr<WindowSystem>   mWindowSystem;
	std::shared_ptr<WorldSystem>    mWorldSystem;
};

inline void Game::setState(GameState state) {
	mState = state;
}

inline auto Game::getState() const {
	return mState;
}

inline auto Game::getMeshManager() {
	return mMeshManager;
}

inline auto Game::getTextureManager() {
	return mTextureManager;
}

inline auto Game::getInputSystem() {
	return mInputSystem;
}

inline auto Game::getRenderSystem() {
	return mRenderSystem;
}

inline auto Game::getMovementSystem() {
	return mMovementSystem;
}

inline auto Game::getSceneSystem() {
	return mSceneSystem;
}

inline auto Game::getWindowSystem() {
	return mWindowSystem;
}

inline auto Game::getWorldSystem() {
	return mWorldSystem;
}

} // namespace engine
