// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix4x4.h"

namespace engine {
namespace math {

template <typename T>
Matrix4x4<T> transpose(Matrix4x4<T> const& value) {
	return Matrix4x4<T>(
			Vector4<T>(value[0][0], value[1][0], value[2][0], value[3][0]),
			Vector4<T>(value[0][1], value[1][1], value[2][1], value[3][1]),
			Vector4<T>(value[0][2], value[1][2], value[2][2], value[3][2]),
			Vector4<T>(value[0][3], value[1][3], value[2][3], value[3][3]));
}

template <typename T>
T const* getPointer(Matrix4x4<T> const& value) {
	return &value[0][0];
}

} // namespace math
} // namespace engine
