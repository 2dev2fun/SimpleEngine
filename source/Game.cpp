// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "System/Window.h"
#include <System/Input/Button.h>
#include <System/Input/Key.h>

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

using namespace engine;
using namespace engine::game;

Game::Game() : mState(State::PLAY) {
	mWindowSystem = std::make_unique<WindowSystem>(this, 1024, 768);
}

Game::~Game() {}

void Game::loop() {
	using namespace std::chrono;
	using namespace std::chrono_literals;
	using namespace std::this_thread;

	auto previousFrame = high_resolution_clock::now();
	auto lag = previousFrame - previousFrame;
	auto referenceFrame = microseconds(16'672);

	while (mState == State::PLAY) {
		auto startFrame = high_resolution_clock::now();
		lag += startFrame - previousFrame;
		previousFrame = startFrame;

		while (lag >= referenceFrame) {
			lag -= referenceFrame;
		}

		mWindowSystem->update();

		auto endFrame = high_resolution_clock::now();
		if ((endFrame - startFrame) < referenceFrame) {
			auto sleepTime = startFrame + referenceFrame - endFrame;
			sleep_for(sleepTime);
		}

		if (mWindowSystem->isKeyReleased(system::input::KEY_ESCAPE)) {
			mState = State::EXIT;
		}

		//auto frameTime = duration_cast<microseconds>(high_resolution_clock::now() - startFrame).count();
		//std::cout << "frame time:\t" << frameTime << " μs."<< std::endl;
	}
}
