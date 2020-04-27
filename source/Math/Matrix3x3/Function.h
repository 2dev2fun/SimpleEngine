// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix3x3.h"

namespace engine {
namespace math {

template <typename T>
Matrix3x3<T> transpose(Matrix3x3<T> const& value) {
	return Matrix3x3<T>(
			Vector3<T>(value[0][0], value[1][0], value[2][0]),
			Vector3<T>(value[0][1], value[1][1], value[2][1]),
			Vector3<T>(value[0][2], value[1][2], value[2][2]));
}

template <typename T>
T const* getPointer(Matrix3x3<T> const& value) {
	return &value[0][0];
}

} // namespace math
} // namespace engine
