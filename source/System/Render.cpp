// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component.h"
#include "Component/Mesh.h"
#include "Component/Transform3D.h"
#include "Game.h"
#include "System/Render.h"
#include "System/Render/Technique/Mesh.h"
#include "System/World.h"
#include "Table.h"

#include <memory>

using namespace engine;

RenderSystem::RenderSystem(Game* game) : mGame(game) {
	mMeshTechnique = std::make_unique<MeshTechnique>(mGame);
}

RenderSystem::~RenderSystem() {}

void RenderSystem::update() {
	mMeshTechnique->update();


	//auto* worldSystem = mGame->getWorldSystem();

	//auto meshTable        = worldSystem->getMeshTable();
	//auto transform3DTable = worldSystem->getTransform3DTable();

	//Mask mask = COMPONENT_MESH | COMPONENT_TRANSFORM3D;

	//for (UInt32 index = 0; index < meshTable->getSize(); ++index) {
		//auto entity = meshTable->getEntity(index);

		//if (!worldSystem->hasComponent(entity, mask)) { continue; }

		//auto* meshComponent = worldSystem->getMeshComponent(entity);
		//auto d1M = meshComponent->getData1();
		//auto d2M = meshComponent->getData2();

		//auto* transform3DComponent = worldSystem->getTransform3DComponent(entity);
		//auto d1T = transform3DComponent->getData1();
		//auto d2T = transform3DComponent->getData2();

		//std::cout << "RenderSystem: " << d1M << '\t' << d2M << '\t' << d1T << '\t' << d2T << std::endl;
	//}
}
