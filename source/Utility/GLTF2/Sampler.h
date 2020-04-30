// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Sampler {
	enum class MagFilter {
		NONE    = 0,
		NEAREST = 9728,
		LINEAR  = 9729,
	};

	enum class MinFilter {
		NONE                   = 0,
		NEAREST                = 9728,
		LINEAR                 = 9729,
		NEAREST_MIPMAP_NEAREST = 9984,
		LINEAR_MIPMAP_NEAREST  = 9985,
		NEAREST_MIPMAP_LINEAR  = 9986,
		LINEAR_MIPMAP_LINEAR   = 9987,
	};

	enum class Wrap {
		CLAMP_TO_EDGE   = 33071,
		MIRRORED_REPEAT = 33648,
		REPEAT          = 10497,
	};

	MagFilter   magFilter = MagFilter::NONE;
	MinFilter   minFilter = MinFilter::NONE;
	Wrap        wrapS     = Wrap::REPEAT;
	Wrap        wrapT     = Wrap::REPEAT;
	std::string name;
};

} // namespace gltf2
} // namespace engine
