// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace engine {

class MeshManager {
public:
	MeshManager();
	~MeshManager();

	auto get(std::string const& path);
private:
	std::unordered_map<std::string, std::shared_ptr<Mesh>> mMeshes;
};

} // namespace engine
