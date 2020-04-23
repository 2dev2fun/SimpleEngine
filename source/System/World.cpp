// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/World.h"
#include <memory>

using namespace engine;

WorldSystem::WorldSystem(Game* game, UInt32 capacity)
		: mGame(game)
		, mSize(0)
		, mCapacity(capacity)
		, mPlayer(0)
		, mMasks(capacity)
		, mMeshTable(std::make_shared<Table<MeshComponent>>(capacity))
		, mTransform3DTable(std::make_shared<Table<Transform3DComponent>>(capacity))
		, mMeshIndices(capacity)
		, mTransform3DIndices(capacity) {}

Entity WorldSystem::createEntity() {
	ASSERT(mSize + 1 < mCapacity);

	Entity entity = mSize++;
	mMasks[entity] = 0;

	return entity;
}

void WorldSystem::removeEntity(Entity entity) {
	if (hasComponent(entity, COMPONENT_MESH))        { removeMeshComponent(entity);        }
	if (hasComponent(entity, COMPONENT_TRANSFORM3D)) { removeTransform3DComponent(entity); }

	Entity lastEntity = --mSize;

	mMasks[entity] = mMasks[lastEntity];

	if (hasComponent(lastEntity, COMPONENT_MESH)) {
		mMeshIndices[entity] = mMeshIndices[lastEntity];
		mMeshTable->setEntity(mMeshIndices[lastEntity], entity);
	}

	if (hasComponent(lastEntity, COMPONENT_TRANSFORM3D)) {
		mTransform3DIndices[entity] = mTransform3DIndices[lastEntity];
		mTransform3DTable->setEntity(mTransform3DIndices[lastEntity], entity);
	}
}

void WorldSystem::update() {
	mMeshTable->update();
	mTransform3DTable->update();
}
