// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component.h"
#include "Game.h"
#include "System/Render/Backend/OpenGL/Shader/Mesh.h"
#include "System/Render/Technique/Mesh.h"
#include "System/World.h"

#include <memory>
#include <string>

using namespace engine;

MeshTechnique::MeshTechnique(Game* game) : mGame(game) {
	mMeshShader = std::make_unique<MeshShader>();
}

MeshTechnique::~MeshTechnique() {}

void MeshTechnique::update() {
	mMeshShader->active();

	auto* worldSystem = mGame->getWorldSystem();

	auto meshTable        = worldSystem->getMeshTable();
	auto transform3DTable = worldSystem->getTransform3DTable();

	Mask mask = COMPONENT_MESH | COMPONENT_TRANSFORM3D;

	for (UInt32 index = 0; index < meshTable->getSize(); ++index) {
		auto entity = meshTable->getEntity(index);

		if (!worldSystem->hasComponent(entity, mask)) { continue; }

		auto* meshComponent = worldSystem->getMeshComponent(entity);

		//auto* transform3DComponent = worldSystem->getTransform3DComponent(entity);

		mMeshShader->setViewProjection(Mat4());
		mMeshShader->setWorldTransform(Mat4());
		meshComponent->draw();
	}
}
