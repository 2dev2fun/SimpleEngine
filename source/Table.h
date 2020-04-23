// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <cstring>
#include <vector>

namespace engine {

template< typename Component>
class Table {
public:
	explicit Table(UInt32 capacity);
	~Table();

	Index createComponent(Entity entity);
	void removeComponent(Index index);

	void setEntity(Index index, Entity entity);
	Entity getEntity(Index index) const;

	UInt32 getSize() const;
	Entity getLastEntity() const;

	void replaceWithLast(Index index);
	void popLast();

	Component* getComponent(Index index);
	void update();
protected:
	UInt32 mSize;
	UInt32 mCapacity;

	std::vector<Entity> mEntities;
	std::vector<Component> mComponents;
};

template <typename Component>
Table<Component>::Table(UInt32 capacity)
		: mSize(0)
		, mCapacity(capacity)
		, mEntities(capacity)
		, mComponents(capacity) {}

template <typename Component>
Table<Component>::~Table() {}

template <typename Component>
Index Table<Component>::createComponent(Entity entity) {
	ASSERT(mSize + 1 <= mCapacity);
	Index index = mSize++;
	mEntities[index] = entity;
	mComponents[index].init();
	return index;
}

template <typename Component>
void Table<Component>::removeComponent(Index index) {
	ASSERT(index < mCapacity);
	replaceWithLast(index);
	popLast();
}

template <typename Component>
void Table<Component>::setEntity(Index index, Entity entity) {
	mEntities[index] = entity;
}

template <typename Component>
Entity Table<Component>::getEntity(Index index) const {
	return mEntities[index];
}

template <typename Component>
UInt32 Table<Component>::getSize() const {
	return mSize;
}

template <typename Component>
UInt32 Table<Component>::getLastEntity() const {
	return mEntities[mSize - 1];
}

template <typename Component>
void Table<Component>::replaceWithLast(Index index) {
	ASSERT(index < mCapacity);
	mEntities[index] = mEntities[mSize - 1];
	std::memcpy(&mComponents[index], &mComponents[mSize - 1], sizeof(Component));
}

template <typename Component>
void Table<Component>::popLast() {
	--mSize;
}

template <typename Component>
Component* Table<Component>::getComponent(Index index) {
	ASSERT(index < mCapacity);
	return &mComponents[index];
}

template <typename Component>
void Table<Component>::update() {
	for (UInt32 i = 0; i < mSize; ++i) { mComponents[i].update(); }
}

} // namespace engine
