// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector3.h"

#include <cmath>

namespace engine {
namespace math {

template <typename T>
Vector3<T> cross(Vector3<T> const& left, Vector3<T> const& right) {
	return Vector3<T>(
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

template <typename T>
T lengthSquared(Vector3<T> const& value) {
	return value.x * value.x + value.y * value.y + value.z * value.z;
}

template <typename T>
T length(Vector3<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector3<T> normalize(Vector3<T> const& value) {
	T length = math::length(value);
	ASSERT(length);
	return Vector3<T>(value.x / length, value.y / length, value.z / length);
}

template <typename T>
T const* getPointer(Vector3<T> const& value) {
	return &value[0];
}

} // namespace math
} // namespace engine
