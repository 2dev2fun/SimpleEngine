// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Material {
	struct PbrMetallicRoughness {
		struct BaseColorTexture {
			Int32 index = -1;
		};

		BaseColorTexture baseColorTexture;
		Float32          metallicFactor  = 1.0f;
		Float32          roughnessFactor = 1.0f;
	};

	PbrMetallicRoughness pbrMetallicRoughness;
	std::string          name;
};

} // namespace gltf2
} // namespace engine
