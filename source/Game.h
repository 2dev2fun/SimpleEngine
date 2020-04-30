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
	GameState getState() const;

	MeshManager*    getMeshManager();
	TextureManager* getTextureManager();

	InputSystem*  getInputSystem();
	RenderSystem* getRenderSystem();
	WindowSystem* getWindowSystem();
	WorldSystem*  getWorldSystem();
private:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	GameState mState;

	std::unique_ptr<MeshManager>    mMeshManager;
	std::unique_ptr<TextureManager> mTextureManager;

	std::unique_ptr<InputSystem>  mInputSystem;
	std::unique_ptr<RenderSystem> mRenderSystem;
	std::unique_ptr<WindowSystem> mWindowSystem;
	std::unique_ptr<WorldSystem>  mWorldSystem;
};

inline void Game::setState(GameState state) {
	mState = state;
}

inline GameState Game::getState() const {
	return mState;
}

inline MeshManager* Game::getMeshManager() {
	return mMeshManager.get();
}

inline TextureManager* Game::getTextureManager() {
	return mTextureManager.get();
}

inline InputSystem* Game::getInputSystem() {
	return mInputSystem.get();
}

inline RenderSystem* Game::getRenderSystem() {
	return mRenderSystem.get();
}

inline WindowSystem* Game::getWindowSystem() {
	return mWindowSystem.get();
}

inline WorldSystem* Game::getWorldSystem() {
	return mWorldSystem.get();
}

} // namespace engine
