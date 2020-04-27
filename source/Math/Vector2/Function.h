// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector2.h"

#include <cmath>

namespace engine {
namespace math {

template <typename T>
T lengthSquared(Vector2<T> const& value) {
	return value.x * value.x + value.y * value.y;
}

template <typename T>
T length(Vector2<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector2<T> normalize(Vector2<T> const& value) {
	T length = math::length(value);
	ASSERT(length);
	return Vector2<T>(value.x / length, value.y / length);
}

template <typename T>
T const* getPointer(Vector2<T> const& value) {
	return &value[0];
}

} // namespace math
} // namespace engine
