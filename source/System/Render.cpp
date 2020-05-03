// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component.h"
#include "Component/Mesh.h"
#include "Component/Transform3D.h"
#include "Game.h"
#include "Math.h"
#include "System/Render.h"
#include "System/Render/Camera/Follow.h"
#include "System/Render/Camera/FPS.h"
#include "System/Render/Camera/Orbit.h"
#include "System/Render/Math.h"
#include "System/Render/Technique/Mesh.h"
#include "System/Window.h"
#include "System/World.h"
#include "Table.h"

#include <glad/glad.h>

#include <memory>

namespace engine {

RenderSystem::RenderSystem(Game* game) : mGame(game), mCameraType(CameraType::Follow) {
	mCamera = std::make_unique<FollowCamera>(mGame);

	mMeshTechnique = std::make_unique<MeshTechnique>(mGame);

	auto windowSystem = mGame->getWindowSystem();
	auto widht  = windowSystem->getWidth();
	auto height = windowSystem->getHeight();

	mProjection = math::perspective(math::toRadians(45.0f), widht, height, 0.1f, 1000.0f);
}

RenderSystem::~RenderSystem() {}

void RenderSystem::update() {
	mCamera->update();

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mMeshTechnique->update();
}

void RenderSystem::camera(CameraType type) {
	if (mCameraType == type) { return; }

	mCameraType = type;

	switch (mCameraType) {
		case CameraType::Follow:
			mCamera = std::make_unique<FollowCamera>(mGame);
			break;
		case CameraType::FPS:
			mCamera = std::make_unique<FPSCamera>(mGame);
			break;
		case CameraType::Orbit:
			mCamera = std::make_unique<OrbitCamera>(mGame);
			break;
		default:
			ASSERT(0);
	}

	mCamera->ideal();
}

} // namespace engine
