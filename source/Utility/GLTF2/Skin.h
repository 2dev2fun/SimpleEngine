// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Skin {
	Int32               inverseBindMatrices = -1;
	std::vector<UInt32> joints;
};

} // namespace gltf2
} // namespace engine
