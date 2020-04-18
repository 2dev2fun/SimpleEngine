// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Window.h"

using namespace engine;
using namespace engine::system::input;

WindowSystem::WindowSystem(Game* game, UInt32 width, UInt32 height)
		: mGame(game)
		, mWindow(nullptr)
		, mWidth(width)
		, mHeight(height){
	for (UInt32 key = 0; key < KEY_SIZE; ++key) {
		mLastFrame.keys   [key] = 0;
		mCurrentFrame.keys[key] = 0;
	}

	for (UInt32 button = 0; button < BUTTON_SIZE; ++button) {
		mLastFrame.mouseButtons   [button] = 0;
		mCurrentFrame.mouseButtons[button] = 0;
	}

	if (!glfwInit()) {
		LOG_ERROR("Failed to initialize GLFW.");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	mWindow = glfwCreateWindow(mWidth, mHeight, "Game", nullptr, nullptr);

	if (mWindow == nullptr) {
		LOG_ERROR("Failed to create GLFW window.");
		glfwTerminate();
	}

	glfwMakeContextCurrent(mWindow);
	glfwSetWindowUserPointer(mWindow, this);
	glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwGetCursorPos(mWindow, &mCurrentFrame.mousePositionX, &mCurrentFrame.mousePositionY);
	glfwGetCursorPos(mWindow, &mLastFrame.mousePositionX,    &mLastFrame.mousePositionY);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_ERROR("Failed to Initialize GLAD.");
	}
}

WindowSystem::~WindowSystem() {
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}

void WindowSystem::update() {
	for (UInt32 key = 0; key < KEY_SIZE; ++key) {
		mLastFrame.keys[key] = mCurrentFrame.keys[key];
		mCurrentFrame.keys[key] = glfwGetKey(mWindow, key);
	}

	for (UInt32 button = 0; button < BUTTON_SIZE; ++button) {
		mLastFrame.mouseButtons[button] = mCurrentFrame.mouseButtons[button];
		mCurrentFrame.mouseButtons[button] = glfwGetMouseButton(mWindow, button);
	}

	mLastFrame.mousePositionX = mCurrentFrame.mousePositionX;
	mLastFrame.mousePositionY = mCurrentFrame.mousePositionY;

	glfwGetCursorPos(mWindow, &mCurrentFrame.mousePositionX, &mCurrentFrame.mousePositionY);

	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}
