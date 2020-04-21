// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Quaternion.h"

#include <ostream>

namespace engine {

template <typename T>
Bool operator==(Quaternion<T> const& left, Quaternion<T> const& right) {
	return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

template <typename T>
Bool operator!=(Quaternion<T> const& left, Quaternion<T> const& right) {
	return !(left == right);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Quaternion<T> const& value) {
	UNUSED(value);
	return os << "Quaternion<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Quaternion<Float32> const& value) {
	UNUSED(value);
	return os << "Quaternion<Float32>";
}

} // namespace engine
