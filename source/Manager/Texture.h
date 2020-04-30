// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace std {

	using namespace engine;

	template <>
	struct hash<Vec3> {
		size_t operator()(Vec3 const& k) const {
			return (hash<Float32>()(k.x) ^ (hash<Float32>()(k.y) ^ (hash<Float32>()(k.z))));
		}
	};

} // namespace std

namespace engine {

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	auto get(std::string const& path);
	auto get(Vec3 const& color);
private:
	std::unordered_map<std::string, std::shared_ptr<Texture>> mFileTextures;
	std::unordered_map<Vec3, std::shared_ptr<Texture>>        mVec3Textures;
};

} // namespace engine
