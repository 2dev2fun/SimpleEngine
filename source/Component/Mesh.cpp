// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component/Mesh.h"

using namespace engine;

void MeshComponent::init() {
	mData1 = 0.0f;
	mData1 = 0.0f;
}

void MeshComponent::free() {}

void MeshComponent::update() {
	std::cout << "MeshComponent:\t" << mData1 << '\t' << mData2 << std::endl;
}
