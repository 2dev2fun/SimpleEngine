// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Manager/Mesh.h"
#include "System/Render/Mesh.h"

#include <memory>
#include <string>

namespace engine {

MeshManager::MeshManager() {}

MeshManager::~MeshManager() {}

auto MeshManager::get(std::string const& path) {
	auto it = mMeshes.find(path);
	if (it != mMeshes.end()) { return it->second; }
	auto mesh = std::make_shared<Mesh>(path);
	mMeshes[path] = mesh;
	return mesh;
}

} // namespace engine
