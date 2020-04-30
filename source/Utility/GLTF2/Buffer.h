// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Buffer {
	Buffer() : byteLength(-1) {}

	std::string        uri;
	Int32              byteLength;
	std::vector<UInt8> data;
};

} // namespace gltf2
} // namespace engine
