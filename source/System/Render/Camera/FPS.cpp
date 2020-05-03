// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "Math.h"
#include "Math/Vector3/Operator.h"
#include "System/Render.h"
#include "System/Render/Camera/FPS.h"
#include "System/Render/Math.h"
#include "System/Window.h"
#include "System/World.h"

namespace engine {

FPSCamera::FPSCamera(Game* game) : Camera(game) {
	mMaxPitch   = math::PI / 3.0f;
	mPitchSpeed = 150.0f;
	mPitch      = 0.0f;
}

FPSCamera::~FPSCamera() {}

void FPSCamera::update() {
	auto windowSystem = mGame->getWindowSystem();
	auto worldSystem  = mGame->getWorldSystem();

	mPitch += windowSystem->getMouseOffsetY() / windowSystem->getHeight();
	mPitch  = math::clamp(mPitch, -mMaxPitch, mMaxPitch);

	auto player = worldSystem->getPlayer();
	ASSERT(worldSystem->hasComponent(player, COMPONENT_TRANSFORM3D));

	auto* transform3DComponent = worldSystem->getTransform3DComponent(worldSystem->getPlayer());

	auto const& forward = transform3DComponent->getForward();
	auto const& right   = transform3DComponent->getRight();
	auto const& eye     = transform3DComponent->getTranslation();

	Quat rotation(right, mPitch);

	Vec3 target = eye + math::transform(forward, rotation) * 100.0f;
	Vec3 up     = math::transform(math::UP, rotation);

	mView = math::lookAt(eye, target, up);
	mGame->getRenderSystem()->setView(mView);
}

} // namespace engine
