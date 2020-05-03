// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"
#include "Math/Vector3.h"
#include "System/Render/Camera.h"

namespace engine {

class FollowCamera : public Camera {
public:
	FollowCamera(Game* game);
	~FollowCamera();

	void ideal() override;
	void update() override;
private:
	Vec3 getCameraPosition(Vec3 const& position, Vec3 const& forward);

	Float32 mHorizontalDistance;
	Float32 mVerticalDistance;
	Float32 mTargetDistance;
	Float32 mSpringContant;

	Vec3 mCameraPosition;
	Vec3 mVelocity;
};

} // namespace engine
