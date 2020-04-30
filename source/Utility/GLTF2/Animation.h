// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <rapidjson/document.h>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

struct Animation {
	struct Sampler {
		enum class Interpolation {
			LINEAR,
			STEP,
			CUBICSPLINE
		};

		UInt32        input;
		UInt32        output;
		Interpolation interpolation = Interpolation::LINEAR;
	};

	struct Channel {
		Channel() : sampler(-1) {}

		struct Target {
			enum class Path {
				translation,
				rotation,
				scale,
				weights
			};

			Target() : node(-1) {}

			Int32 node;
			Path  path;
		};

		Int32  sampler;
		Target target;
	};

	void load(rj::Value& animation);

	std::vector<Sampler> mSamplers;
	std::vector<Channel> mChannels;
};

} // namespace gltf2
} // namespace engine
