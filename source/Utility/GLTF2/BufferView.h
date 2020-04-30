// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct BufferView {
	BufferView() : buffer(-1), byteOffset(-1), byteLength(-1), byteStride(-1), target(-1) {}

	Int32 buffer;
	Int32 byteOffset;
	Int32 byteLength;
	Int32 byteStride;
	Int32 target;
};

} // namespace gltf2
} // namespace engine
