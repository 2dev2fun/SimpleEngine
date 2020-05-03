// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Render/Camera.h"

namespace engine {

class FPSCamera : public Camera {
public:
	FPSCamera(Game* game);
	~FPSCamera();

	void ideal() override {}
	void update() override;
private:
	Float32 mPitchSpeed;
	Float32 mMaxPitch;
	Float32 mPitch;
};

} // namespace engine
