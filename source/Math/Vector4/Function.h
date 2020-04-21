// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector4.h"

#include <cmath>

namespace engine {
namespace math {

template <typename T>
T lengthSquared(Vector4<T> const& value) {
	return value.x * value.x + value.y * value.y + value.z * value.z + value.w * value.w;
}

template <typename T>
T length(Vector4<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector4<T> normalize(Vector4<T> const& value) {
	T length = math::length(value);
	ASSERT(length);
	return Vector4<T>(value.x / length, value.y / length, value.z / length, value.w / length);
}

} // namespace math
} // namespace engine
