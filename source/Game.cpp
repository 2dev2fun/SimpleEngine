#include "Game.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace engine;

Game::Game() : mState(GameState::PLAY) {}

Game::~Game() {}

void Game::loop() {
	using namespace std::chrono;
	using namespace std::chrono_literals;
	using namespace std::this_thread;

	auto previousFrame = high_resolution_clock::now();
	auto lag = previousFrame - previousFrame;
	auto referenceFrame = microseconds(16'672);

	while (mState == GameState::PLAY) {
		auto startFrame = high_resolution_clock::now();
		lag += startFrame - previousFrame;
		previousFrame = startFrame;

		while (lag >= referenceFrame) {
			lag -= referenceFrame;
		}

		auto endFrame = high_resolution_clock::now();
		if ((endFrame - startFrame) < referenceFrame) {
			auto sleepTime = startFrame + referenceFrame - endFrame;
			sleep_for(sleepTime);
		}

		auto frameTime = duration_cast<microseconds>(high_resolution_clock::now() - startFrame).count();
		std::cout << "frame time:\t" << frameTime << " μs."<< std::endl;
	}
}
