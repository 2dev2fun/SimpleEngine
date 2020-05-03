// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "Math.h"
#include "Math/Matrix4x4.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"
#include "Math/Vector3/Function.h"
#include "Math/Vector3/Operator.h"
#include "System/Render.h"
#include "System/Render/Camera/Orbit.h"
#include "System/Render/Math.h"
#include "System/Window.h"
#include "System/World.h"

namespace engine {

OrbitCamera::OrbitCamera(Game* game) : Camera(game), mYawSpeed(0.0f), mPitchSpeed(0.0f) {
	mOffset = Vec3(0.0f, 1.0f, 5.0f);
	mUp     = math::UP;
}

OrbitCamera::~OrbitCamera() {}

void OrbitCamera::update() {
	auto windowSystem = mGame->getWindowSystem();

	auto offsetX = windowSystem->getMouseOffsetX() / windowSystem->getWidth();
	auto offsetY = windowSystem->getMouseOffsetY() / windowSystem->getHeight();

	if (!math::nearZero(offsetX, 0.01f)) { mYawSpeed   = 100.0f * offsetX; }
	if (!math::nearZero(offsetY, 0.01f)) { mPitchSpeed = 100.0f * offsetY; }

	Quat yaw(math::UP, mYawSpeed * DELTA_TIME);

	mOffset = math::transform(mOffset, yaw);
	mUp     = math::transform(mUp, yaw);

	Vec3 forward = math::normalize(math::invert(mOffset));
	Vec3 right   = math::normalize(math::cross(mUp, forward));

	Quat pitch(right, mPitchSpeed * DELTA_TIME);

	mOffset = math::transform(mOffset, pitch);
	mUp     = math::transform(mUp, pitch);

	auto worldSystem = mGame->getWorldSystem();
	auto* transform3DComponent = worldSystem->getTransform3DComponent(worldSystem->getPlayer());

	auto const& target = transform3DComponent->getTranslation();
	Vec3 cameraPosition = target + mOffset;

	mYawSpeed -= 0.1f * mYawSpeed;
	if (mYawSpeed < 0) { mYawSpeed = 0; }

	mPitchSpeed -= 0.1f * mPitchSpeed;
	if (mPitchSpeed < 0) { mPitchSpeed = 0; }

	mView = math::lookAt(cameraPosition, target, mUp);
	mGame->getRenderSystem()->setView(mView);
}

} // namespace engine
