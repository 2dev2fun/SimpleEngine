// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Game.h"
#include "Command/Exit.h"
#include "Command/Test.h"
#include "Command/PlayerBackward.h"
#include "Command/PlayerForward.h"
#include "Command/PlayerLeft.h"
#include "Command/PlayerOverviewStart.h"
#include "Command/PlayerOverviewStop.h"
#include "Command/PlayerRight.h"
#include "Command/PlayerRotation.h"
#include "System/Input.h"
#include "System/Scene.h"
#include "System/World.h"

#include <memory>
#include <string>

namespace engine {

SceneSystem::SceneSystem(Game* game) : mGame(game) {
	auto inputSystem = mGame->getInputSystem();
	inputSystem->attachCommand(std::make_shared<ExitCommand>(          mGame, KEY_ESCAPE, STATE_RELEASED));
	inputSystem->attachCommand(std::make_shared<TestCommand>(          mGame, KEY_T,      STATE_PRESSED));
	inputSystem->attachCommand(std::make_shared<PlayerForwardCommand>( mGame, KEY_W,      STATE_HELD));
	inputSystem->attachCommand(std::make_shared<PlayerBackwardCommand>(mGame, KEY_S,      STATE_HELD));
	inputSystem->attachCommand(std::make_shared<PlayerLeftCommand>(    mGame, KEY_A,      STATE_HELD));
	inputSystem->attachCommand(std::make_shared<PlayerRightCommand>(   mGame, KEY_D,      STATE_HELD));
	inputSystem->attachCommand(std::make_shared<PlayerRotationCommand>(mGame));
	inputSystem->attachCommand(std::make_shared<PlayerOverviewStartCommand>(mGame, BUTTON_1, STATE_PRESSED));
	inputSystem->attachCommand(std::make_shared<PlayerOverviewStopCommand>(mGame,  BUTTON_1, STATE_RELEASED));

	auto worldSystem = mGame->getWorldSystem();

	std::string const dir = "/data/project/glTF-Sample-Models/2.0";
	std::string const obj = "/Box/glTF/Box.gltf";

	auto mesh = std::make_shared<Mesh>(dir + obj);

	{
		auto entity = worldSystem->createEntity();

		auto* meshComponent = worldSystem->createMeshComponent(entity);
		meshComponent->setMesh(mesh);

		auto* moveComponent = worldSystem->createMoveComponent(entity);
		UNUSED(moveComponent);

		auto* transform3DComponent = worldSystem->createTransform3DComponent(entity);
		UNUSED(transform3DComponent);

		worldSystem->setPlayer(entity);
	}

	{
		auto entity = worldSystem->createEntity();

		auto* meshComponent = worldSystem->createMeshComponent(entity);
		meshComponent->setMesh(mesh);

		auto* transform3DComponent = worldSystem->createTransform3DComponent(entity);
		UNUSED(transform3DComponent);

		transform3DComponent->setTranslation(Vec3(0.0f, 0.0f, -2.0f));
	}
}

SceneSystem::~SceneSystem() {}

void SceneSystem::update() {}

} // namespace engine
