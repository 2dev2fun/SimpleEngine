// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Render/Mesh.h"

#include <memory>
#include <vector>

namespace engine {

class MeshComponent {
public:
	void init();
	void free();

	void update();

	void setMesh(std::shared_ptr<Mesh> mesh);
	auto getMesh();

	void draw();
private:
	std::shared_ptr<Mesh> mMesh;
};

inline void MeshComponent::setMesh(std::shared_ptr<Mesh> mesh) {
	mMesh = mesh;
}

inline auto MeshComponent::getMesh() {
	return mMesh;
}

inline void MeshComponent::draw() {
	mMesh->draw();
}

} // namespace engine
