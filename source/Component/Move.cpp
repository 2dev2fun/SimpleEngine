// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component/Move.h"

namespace engine {

void MoveComponent::init() {
	mAngularSpeed = 100.0f;
	mAngularValue = 0.0f;

	mForwardSpeed = 100.0f;
	mForwardValue = 0.0f;

	mStrafeSpeed = 100.0f;
	mStrafeValue = 0.0f;
}

void MoveComponent::free() {}

void MoveComponent::update() {}

} // namespace engine
