// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/Asset.h"
#include <rapidjson/document.h>

namespace engine {
namespace gltf2 {

void Asset::load(rj::Value& asset) {
	auto versionIt = asset.FindMember("version");
	ASSERT(versionIt != asset.MemberEnd());

	auto& version = versionIt->value;
	ASSERT(version.IsString());

	mVersion = version.GetString();
}

} // namespace gltf2
} // namespace engine
