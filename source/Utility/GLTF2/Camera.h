// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {
namespace gltf2 {

struct Camera {
	struct Perspective {
		Float32 aspectRation;
		Float32 yfov;
		Float32 zfar;
		Float32 znear;
	};

	struct Orthographic {
		Float32 xmag;
		Float32 ymag;
		Float32 zfar;
		Float32 znear;
	};

	Perspective perspective;
	Orthographic orthographic;
};

} // namespace gltf2
} // namespace engine
