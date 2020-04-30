// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/Exit.h"
#include "Command/Test.h"
#include "Component/Mesh.h"
#include "Component/Transform3D.h"
#include "Game.h"
#include "Manager/Mesh.h"
#include "Manager/Texture.h"
#include "System/Input.h"
#include "System/Render.h"
#include "System/Render/Mesh.h"
#include "System/Window.h"
#include "System/World.h"
#include "Utility/GLTF2.h"

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using namespace engine;

Game::Game() : mState(GAME_STATE_PLAY) {
	mMeshManager    = std::make_unique<MeshManager>();
	mTextureManager = std::make_unique<TextureManager>();

	mInputSystem  = std::make_unique<InputSystem>(this);
	mWindowSystem = std::make_unique<WindowSystem>(this, 1024, 768);
	mRenderSystem = std::make_unique<RenderSystem>(this);
	mWorldSystem  = std::make_unique<WorldSystem>(this, 100);

	mInputSystem->attachCommand(std::make_unique<ExitCommand>(this, KEY_ESCAPE, STATE_RELEASED));
	mInputSystem->attachCommand(std::make_unique<TestCommand>(this, KEY_T,      STATE_PRESSED));
}

Game::~Game() {
	mWorldSystem.release();
	mInputSystem.release();
	mRenderSystem.release();
	mWorldSystem.release();
}

void Game::loop() {

	std::string const dir = "/data/project/glTF-Sample-Models/2.0";
	std::string const obj = "/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf";

	//-------------------------------------------------------------------------

	auto entity = mWorldSystem->createEntity();

	auto* meshComponent = mWorldSystem->createMeshComponent(entity);
	meshComponent->setMesh(std::make_shared<Mesh>(dir + obj));

	auto* transform3DComponent = mWorldSystem->createTransform3DComponent(entity);
	UNUSED(transform3DComponent);

	//-------------------------------------------------------------------------

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
