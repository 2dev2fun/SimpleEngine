// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Input/Button.h"
#include "System/Input/Key.h"
#include "System/Input/State.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

class Game;

class WindowSystem {
public:
	WindowSystem(Game* game, UInt32 width, UInt32 height);
	~WindowSystem();

	void update();

	Bool isKeyPressed(system::input::Key key) const;
	Bool isKeyReleased(system::input::Key key) const;
	Bool isKeyHeld(system::input::Key key) const;

	Bool isMouseButtonPressed(system::input::Button button) const;
	Bool isMouseButtonReleased(system::input::Button button) const;
	Bool isMouseButtonHeld(system::input::Button button) const;

	Float32 getMousePositionX() const;
	Float32 getMousePositionY() const;

	Float32 getMouseOffsetX() const;
	Float32 getMouseOffsetY() const;

	UInt32 getWindowWidth() const;
	UInt32 getWindowHeight() const;
private:
	Game* mGame;

	GLFWwindow* mWindow;

	UInt32 mWidth;
	UInt32 mHeight;

	struct Frame {
		UInt8   keys[system::input::KEY_SIZE];
		UInt8   mouseButtons[system::input::BUTTON_SIZE];
		Float64 mousePositionX;
		Float64 mousePositionY;
	};

	Frame mLastFrame;
	Frame mCurrentFrame;
};

inline Bool WindowSystem::isKeyPressed(system::input::Key key) const {
	return mCurrentFrame.keys[key] && !mLastFrame.keys[key];
}

inline Bool WindowSystem::isKeyReleased(system::input::Key key) const {
	return !mCurrentFrame.keys[key] && mLastFrame.keys[key];
}

inline Bool WindowSystem::isKeyHeld(system::input::Key key) const {
	return mCurrentFrame.keys[key] && mLastFrame.keys[key];
}

inline Bool WindowSystem::isMouseButtonPressed(system::input::Button button) const {
	return mCurrentFrame.mouseButtons[button] && !mLastFrame.mouseButtons[button];
}

inline Bool WindowSystem::isMouseButtonReleased(system::input::Button button) const {
	return !mCurrentFrame.mouseButtons[button] && mLastFrame.mouseButtons[button];
}

inline Bool WindowSystem::isMouseButtonHeld(system::input::Button button) const {
	return mCurrentFrame.mouseButtons[button] && mLastFrame.mouseButtons[button];
}

inline Float32 WindowSystem::getMousePositionX() const {
	return mCurrentFrame.mousePositionX;
}

inline Float32 WindowSystem::getMouseOffsetX() const {
	return mLastFrame.mousePositionX - mCurrentFrame.mousePositionX;
}

inline Float32 WindowSystem::getMousePositionY() const {
	return mCurrentFrame.mousePositionY;
}

inline Float32 WindowSystem::getMouseOffsetY() const {
	return mLastFrame.mousePositionY - mCurrentFrame.mousePositionY;
}

inline UInt32 WindowSystem::getWindowWidth() const {
	return mWidth;
}

inline UInt32 WindowSystem::getWindowHeight() const {
	return mHeight;
}

} // namespace engine
