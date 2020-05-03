// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Input/Button.h"
#include "System/Input/Key.h"
#include "System/Input/State.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

class WindowSystem {
public:
	WindowSystem(Game* game, UInt32 width, UInt32 height);
	~WindowSystem();

	void update();

	Bool isKey(Key key, State state) const;
	Bool isMouseButton(Button button, State state) const;

	Bool isKeyPressed(Key key) const;
	Bool isKeyReleased(Key key) const;
	Bool isKeyHeld(Key key) const;

	Bool isMouseButtonPressed(Button button) const;
	Bool isMouseButtonReleased(Button button) const;
	Bool isMouseButtonHeld(Button button) const;

	Float32 getMousePositionX() const;
	Float32 getMousePositionY() const;

	Float32 getMouseOffsetX() const;
	Float32 getMouseOffsetY() const;

	UInt32 getWidth() const;
	UInt32 getHeight() const;
private:
	Game* mGame;
	GLFWwindow* mWindow;

	UInt32 mWidth;
	UInt32 mHeight;

	struct Frame {
		UInt8   keys[KEY_SIZE];
		UInt8   mouseButtons[BUTTON_SIZE];
		Float64 mousePositionX;
		Float64 mousePositionY;
	};

	Frame mLastFrame;
	Frame mCurrentFrame;
};

inline Bool WindowSystem::isKeyPressed(Key key) const {
	return mCurrentFrame.keys[key] && !mLastFrame.keys[key];
}

inline Bool WindowSystem::isKeyReleased(Key key) const {
	return !mCurrentFrame.keys[key] && mLastFrame.keys[key];
}

inline Bool WindowSystem::isKeyHeld(Key key) const {
	return mCurrentFrame.keys[key] && mLastFrame.keys[key];
}

inline Bool WindowSystem::isMouseButtonPressed(Button button) const {
	return mCurrentFrame.mouseButtons[button] && !mLastFrame.mouseButtons[button];
}

inline Bool WindowSystem::isMouseButtonReleased(Button button) const {
	return !mCurrentFrame.mouseButtons[button] && mLastFrame.mouseButtons[button];
}

inline Bool WindowSystem::isMouseButtonHeld(Button button) const {
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

inline UInt32 WindowSystem::getWidth() const {
	return mWidth;
}

inline UInt32 WindowSystem::getHeight() const {
	return mHeight;
}

} // namespace engine
