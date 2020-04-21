// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector3.h"

#include <ostream>

namespace engine {

template <typename T>
Bool operator==(Vector3<T> const& left, Vector3<T> const& right) {
	return left.x == right.x && left.y == right.y && left.z == right.z;
}

template <typename T>
Bool operator!=(Vector3<T> const& left, Vector3<T> const& right) {
	return !(left == right);
}

template <typename T>
Vector3<T> operator+(Vector3<T> const& left, Vector3<T> const& right) {
	return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template <typename T>
Vector3<T> operator-(Vector3<T> const& left, Vector3<T> const& right) {
	return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template <typename T>
T operator*(Vector3<T> const& left, Vector3<T> const& right) {
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

template <typename T, typename U>
Vector3<T> operator+(Vector3<T> const& left, U right) {
	return Vector3<T>(left.x + right, left.y + right, left.z + right);
}

template <typename T, typename U>
Vector3<T> operator-(Vector3<T> const& left, U right) {
	return Vector3<T>(left.x - right, left.y - right, left.z - right);
}

template <typename T, typename U>
Vector3<T> operator*(Vector3<T> const& left, U right) {
	return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template <typename T, typename U>
Vector3<T> operator+(U left, Vector3<T> const& right) {
	return Vector3<T>(left + right.x, left + right.y, left + right.z);
}

template <typename T, typename U>
Vector3<T> operator*(U left, Vector3<T> const& right) {
	return Vector3<T>(left * right.x, left * right.y, left * right.z);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector3<T> const& value) {
	UNUSED(value);
	return os << "Vector3<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Vector3<Float32> const& value) {
	UNUSED(value);
	return os << "Vector3<Float32>";
}

} // namespace engine
