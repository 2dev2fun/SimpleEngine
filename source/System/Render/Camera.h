// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"

namespace engine {

class Camera {
public:
	virtual ~Camera();

	virtual void update() = 0;
	virtual void ideal() = 0;
protected:
	Camera(Game* game);

	Game* mGame;
	Mat4 mView;
};

} // namespace engine
