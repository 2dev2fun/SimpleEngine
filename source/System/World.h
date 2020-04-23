// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Component.h"
#include "Component/Mesh.h"
#include "Component/Transform3D.h"
#include "Engine.h"
#include "Table.h"

#include <memory>
#include <vector>

namespace engine {

class WorldSystem {
public:
	WorldSystem(Game* game, UInt32 capacity);

	void update();

	Entity createEntity();
	void removeEntity(Entity entity);

	auto* createMeshComponent(Entity entity);
	auto* createTransform3DComponent(Entity entity);

	void removeMeshComponent(Entity entity);
	void removeTransform3DComponent(Entity entity);

	auto* getMeshComponent(Entity entity);
	auto* getTransform3DComponent(Entity entity);

	Bool hasEntity(Entity entity) const;
	Bool hasComponent(Entity entity, Mask mask) const;

	auto getMeshTable();
	auto getTransform3DTable();

	void setPlayer(Entity entity);
	Entity getPlayer() const;

	UInt32 getSize() const;
	UInt32 getCapacity() const;
private:
	Index getMeshIndex(Entity entity) const;
	Index getTransform3DIndex(Entity entity) const;

	void attachMask(Entity entity, Mask mask);
	void detachMask(Entity entity, Mask mask);

	template <typename Table>
	Index createComponent(Table* table, std::vector<Index>& indices, Entity entity, Mask mask);

	template <typename Table>
	void removeComponent(Table* table, std::vector<Index>& indices, Entity entity, Mask mask);

	Game* mGame;

	UInt32 mSize;
	UInt32 mCapacity;

	Entity mPlayer;

	std::vector<Mask> mMasks;

	std::shared_ptr<Table<MeshComponent>>        mMeshTable;
	std::shared_ptr<Table<Transform3DComponent>> mTransform3DTable;

	std::vector<Index> mMeshIndices;
	std::vector<Index> mTransform3DIndices;
};

inline auto* WorldSystem::createMeshComponent(Entity entity) {
	ASSERT(entity < mSize);
	auto index = createComponent(mMeshTable.get(), mMeshIndices, entity, COMPONENT_MESH);
	return mMeshTable->getComponent(index);
}

inline auto* WorldSystem::createTransform3DComponent(Entity entity) {
	ASSERT(entity < mSize);
	auto index = createComponent(mTransform3DTable.get(), mTransform3DIndices, entity, COMPONENT_TRANSFORM3D);
	return mTransform3DTable->getComponent(index);
}

inline void WorldSystem::removeMeshComponent(Entity entity) {
	ASSERT(entity < mSize);
	removeComponent(mMeshTable.get(), mMeshIndices, entity, COMPONENT_MESH);
}

inline void WorldSystem::removeTransform3DComponent(Entity entity) {
	ASSERT(entity < mSize);
	removeComponent(mTransform3DTable.get(), mTransform3DIndices, entity, COMPONENT_TRANSFORM3D);
}

inline auto* WorldSystem::getMeshComponent(Entity entity) {
	ASSERT(entity < mSize);
	return mMeshTable->getComponent(getMeshIndex(entity));
}

inline auto* WorldSystem::getTransform3DComponent(Entity entity) {
	ASSERT(entity < mSize);
	return mTransform3DTable->getComponent(getTransform3DIndex(entity));
}

inline Bool WorldSystem::hasEntity(Entity entity) const {
	return entity < mSize;
}

inline Bool WorldSystem::hasComponent(Entity entity, Mask mask) const {
	return (mMasks[entity] & mask) == mask;
}

inline Index WorldSystem::getMeshIndex(Entity entity) const {
	ASSERT(entity < mSize);
	return mMeshIndices[entity];
}

inline Index WorldSystem::getTransform3DIndex(Entity entity) const {
	ASSERT(entity < mSize);
	return mTransform3DIndices[entity];
}

inline auto WorldSystem::getMeshTable() {
	return mMeshTable;
}

inline auto WorldSystem::getTransform3DTable() {
	return mTransform3DTable;
}

inline void WorldSystem::setPlayer(Entity entity) {
	mPlayer = entity;
}

inline Entity WorldSystem::getPlayer() const {
	return mPlayer;
}

inline UInt32 WorldSystem::getSize() const {
	return mSize;
}

inline UInt32 WorldSystem::getCapacity() const {
	return mCapacity;
}

inline void WorldSystem::attachMask(Entity entity, Mask mask) {
	mMasks[entity] |= mask;
}

inline void WorldSystem::detachMask(Entity entity, Mask mask) {
	mMasks[entity] &= ~mask;
}

template <typename Table>
Index WorldSystem::createComponent(Table* table, std::vector<Index>& indices, Entity entity, Mask mask) {
	ASSERT(entity < mSize);

	auto index = table->createComponent(entity);
	attachMask(entity, mask);
	indices[entity] = index;

	return index;
}

template <typename Table>
void WorldSystem::removeComponent(Table* table, std::vector<Index>& indices, Entity entity, Mask mask) {
	ASSERT(entity < mSize);

	auto index = indices[entity];
	detachMask(entity, mask);
	auto lastEntity = table->getLastEntity();
	table->removeComponent(index);
	indices[lastEntity] = index;
}

} // namespace engine
