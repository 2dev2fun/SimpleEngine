// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component/Transform3D.h"
#include "Game.h"
#include "Math.h"
#include "Math/Vector3.h"
#include "Math/Vector3/Operator.h"
#include "System/Render.h"
#include "System/Render/Camera/Follow.h"
#include "System/Render/Math.h"
#include "System/World.h"

namespace engine {

FollowCamera::FollowCamera(Game* game)
		: Camera(game)
		, mHorizontalDistance(5.0f)
		, mVerticalDistance(1.0f)
		, mTargetDistance(10.0f)
		, mSpringContant(128.0f) {}

FollowCamera::~FollowCamera() {}

void FollowCamera::ideal() {
	auto worldSystem = mGame->getWorldSystem();

	auto* transform3DComponent = worldSystem->getTransform3DComponent(worldSystem->getPlayer());

	auto const& playerPosition = transform3DComponent->getTranslation();
	auto const& playerForward  = transform3DComponent->getForward();

	mCameraPosition = getCameraPosition(playerPosition, playerForward);
}

void FollowCamera::update() {
	auto worldSystem = mGame->getWorldSystem();

	auto* transform3DComponent = worldSystem->getTransform3DComponent(worldSystem->getPlayer());

	auto const& playerPosition = transform3DComponent->getTranslation();
	auto const& playerForward  = transform3DComponent->getForward();

	Vec3 difference   =  mCameraPosition - getCameraPosition(playerPosition, playerForward);
	Vec3 acceleration = -mSpringContant * difference - 2.0f * math::sqrt(mSpringContant) * mVelocity;

	mVelocity       += acceleration * DELTA_TIME;
	mCameraPosition += mVelocity    * DELTA_TIME;

	Vec3 target = playerPosition + playerForward * mTargetDistance;
	mView = math::lookAt(mCameraPosition, target, math::UP);
	mGame->getRenderSystem()->setView(mView);
}

Vec3 FollowCamera::getCameraPosition(Vec3 const& position, Vec3 const& forward) {
	return position - forward * mHorizontalDistance + math::UP * mVerticalDistance;
}

} // namespace engine
