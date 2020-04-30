// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <rapidjson/document.h>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

class Asset {
public:
	Bool hasVersion();
	auto getVersion();

	void load(rj::Value& asset);
private:
	std::string mVersion;
};

inline Bool Asset::hasVersion() {
	return mVersion.size() > 0;
}

inline auto Asset::getVersion() {
	ASSERT(hasVersion());
	return mVersion;
}

} // namespace gltf2
} // namespace engine
