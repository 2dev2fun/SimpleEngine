// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component/Transform3D.h"
#include "Math.h"
#include "Math/Matrix4x4.h"
#include "Math/Matrix4x4/Operator.h"
#include "System/Render/Math.h"

namespace engine {

void Transform3DComponent::init() {
	mRecompute      = true;
	mTranslation    = Vec3(0.0f);
	mScale          = 1.0f;
	mRotation       = Quat();
	mForward        = math::FORWARD;
	mRight          = math::RIGHT;
	mWorldTransform = Mat4();
}

void Transform3DComponent::free() {}

void Transform3DComponent::update() {
	if (!mRecompute) { return; }

	mWorldTransform = math::createTranslation(mTranslation);
	mWorldTransform = mWorldTransform * math::createRotation(mRotation);
	mWorldTransform = mWorldTransform * math::createScale(mScale);

	mForward = math::transform(math::FORWARD, mRotation);
	mRight   = math::transform(math::RIGHT,   mRotation);

	mRecompute = false;
}

} // namespace engine
