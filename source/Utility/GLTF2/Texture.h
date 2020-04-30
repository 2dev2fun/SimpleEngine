// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Texture {
	Int32       sampler = -1;
	Int32       source  = -1;
	std::string name;
};

} // namespace gltf2
} // namespace engine
