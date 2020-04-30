// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Manager/Texture.h"
#include "Math/Vector3/Operator.h"
#include "System/Render/Backend/OpenGL/Texture.h"

#include <memory>
#include <string>

using namespace engine;

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

auto TextureManager::get(std::string const& path) {
	auto it = mFileTextures.find(path);
	if (it != mFileTextures.end()) { return it->second; }
	auto texture = std::make_shared<Texture>(path);
	mFileTextures[path] = texture;
	return texture;
}

auto TextureManager::get(Vec3 const& color) {
	auto it = mVec3Textures.find(color);
	if (it != mVec3Textures.end()) { return it->second; }
	auto texture = std::make_shared<Texture>(color);
	mVec3Textures[color] = texture;
	return texture;
}
