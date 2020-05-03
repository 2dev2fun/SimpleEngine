// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "Manager/Mesh.h"
#include "Manager/Texture.h"
#include "System/Input.h"
#include "System/Movement.h"
#include "System/Render.h"
#include "System/Scene.h"
#include "System/Window.h"
#include "System/World.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

namespace engine {

Game::Game() : mState(GAME_STATE_PLAY) {
	mMeshManager    = std::make_shared<MeshManager>();
	mTextureManager = std::make_shared<TextureManager>();

	mInputSystem    = std::make_shared<InputSystem>(this);
	mWindowSystem   = std::make_shared<WindowSystem>(this, 1024, 768);
	mWorldSystem    = std::make_shared<WorldSystem>(this, 100);
	mRenderSystem   = std::make_shared<RenderSystem>(this);
	mSceneSystem    = std::make_shared<SceneSystem>(this);
	mMovementSystem = std::make_shared<MovementSystem>(this);
}

Game::~Game() {
	mMovementSystem = nullptr;
	mSceneSystem    = nullptr;
	mWorldSystem    = nullptr;
	mInputSystem    = nullptr;
	mRenderSystem   = nullptr;
	mWorldSystem    = nullptr;
}

void Game::loop() {
	using namespace std::chrono;
	using namespace std::chrono_literals;
	using namespace std::this_thread;

	auto previousFrame = high_resolution_clock::now();
	auto lag = previousFrame - previousFrame;
	auto referenceFrame = microseconds(16'672);

	while (mState == GAME_STATE_PLAY) {
		auto startFrame = high_resolution_clock::now();
		lag += startFrame - previousFrame;
		previousFrame = startFrame;

		while (lag >= referenceFrame) {
			lag -= referenceFrame;
		}

		mWindowSystem->update();
		mInputSystem->update();
		mWorldSystem->update();
		mMovementSystem->update();
		mRenderSystem->update();

		auto endFrame = high_resolution_clock::now();
		if ((endFrame - startFrame) < referenceFrame) {
			auto sleepTime = startFrame + referenceFrame - endFrame;
			sleep_for(sleepTime);
		}

		//auto frameTime = duration_cast<microseconds>(high_resolution_clock::now() - startFrame).count();
		//std::cout << "frame time:\t" << frameTime << " μs."<< std::endl;
	}
}

} // namespace engine
