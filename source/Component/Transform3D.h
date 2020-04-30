// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"

namespace engine {

class Transform3DComponent {
public:
	void init();
	void free();

	void update();
private:
	Bool    mRecompute;

	Vec3    mTransform;
	Float32 mScale;
	Quat    mRotation;

	Vec3    mForward;
	Vec3    mRight;

	Mat4    mWorldTransform;
};

} // namespace engine
