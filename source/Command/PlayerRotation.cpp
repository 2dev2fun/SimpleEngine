// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Command/PlayerRotation.h"
#include "Game.h"
#include "Math.h"
#include "System/Window.h"
#include "System/World.h"

namespace engine {

PlayerRotationCommand::PlayerRotationCommand(Game* game) : Command(game) {}

PlayerRotationCommand::~PlayerRotationCommand() {}

void PlayerRotationCommand::execute() {
	auto windowSystem = mGame->getWindowSystem();
	auto worldSystem  = mGame->getWorldSystem();

	Float32 offsetX = windowSystem->getMouseOffsetX() / windowSystem->getWidth();

	if (!math::nearZero(offsetX)) {
		auto* moveComponent = worldSystem->getMoveComponent(worldSystem->getPlayer());

		auto angularValue = moveComponent->getAngularValue();
		auto angularSpeed = moveComponent->getAngularSpeed();

		moveComponent->setAngularValue(angularValue + angularSpeed * offsetX);
	}
}

} // namespace engine
