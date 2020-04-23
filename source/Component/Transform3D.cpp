// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Component/Transform3D.h"

using namespace engine;

void Transform3DComponent::init() {
	mData1 = 0.0f;
	mData1 = 0.0f;
}

void Transform3DComponent::free() {}

void Transform3DComponent::update() {
	std::cout << "Transform3DComponent:\t" << mData1 << '\t' << mData2 << std::endl;
}
