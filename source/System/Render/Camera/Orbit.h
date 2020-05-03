// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"
#include "System/Render/Camera.h"

namespace engine {

class OrbitCamera : public Camera {
public:
	OrbitCamera(Game* game);
	~OrbitCamera();

	void ideal() override {}
	void update() override;
private:
	Float32 mYawSpeed;
	Float32 mPitchSpeed;

	Vec3 mUp;
	Vec3 mOffset;
};

} // namespace engine
