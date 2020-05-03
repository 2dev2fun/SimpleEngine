// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "Math.h"
#include "Math/Quaternion.h"
#include "Math/Quaternion/Function.h"
#include "Math/Vector3.h"
#include "Math/Vector3/Operator.h"
#include "System/Movement.h"
#include "System/World.h"

namespace engine {

MovementSystem::MovementSystem(Game* game) : mGame(game) {}

MovementSystem::~MovementSystem() {}

void MovementSystem::update() {
	auto worldSystem = mGame->getWorldSystem();

	auto moveTable        = worldSystem->getMoveTable();
	auto transform3DTable = worldSystem->getTransform3DTable();

	Mask mask = COMPONENT_MOVE | COMPONENT_TRANSFORM3D;

	for (UInt32 index = 0; index < moveTable->getSize(); ++index) {
		auto entity = moveTable->getEntity(index);

		if (!worldSystem->hasComponent(entity, mask)) { continue; }

		auto* moveComponent        = worldSystem->getMoveComponent(entity);
		auto* transform3DComponent = worldSystem->getTransform3DComponent(entity);

		Float32 angularValue = moveComponent->getAngularValue();
		Float32 forwardValue = moveComponent->getForwardValue();
		Float32 strafeValue  = moveComponent->getStrafeValue();

		if (!math::nearZero(angularValue)) {
			auto rotation = transform3DComponent->getRotation();
			auto angle    = angularValue * DELTA_TIME;
			transform3DComponent->setRotation(math::concatenate(rotation, Quat(math::UP, angle)));
		}

		if (!math::nearZero(forwardValue) || !math::nearZero(strafeValue)) {
			auto const& forward = transform3DComponent->getForward();
			auto const& right   = transform3DComponent->getRight();

			Vec3 position = transform3DComponent->getTranslation();
			position += forward * forwardValue * DELTA_TIME;
			position += right   * strafeValue  * DELTA_TIME;
			transform3DComponent->setTranslation(position);
		}

		moveComponent->setAngularValue(0.0f);
		moveComponent->setForwardValue(0.0f);
		moveComponent->setStrafeValue(0.0f);
	}
}

} // namespace engine
