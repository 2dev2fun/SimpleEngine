// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix4x4.h"
#include "Math/Vector4/Operator.h"

#include <ostream>

namespace engine {

template <typename T>
Bool operator==(Matrix4x4<T> const& left, Matrix4x4<T> const& right) {
	return left[0] == right[0] && left[1] == right[1] && left[2] == right[2] && left[3] == right[3];
}

template <typename T>
Bool operator!=(Matrix4x4<T> const& left, Matrix4x4<T> const& right) {
	return !(left == right);
}

template <typename T>
Matrix4x4<T> operator+(Matrix4x4<T> const& left, Matrix4x4<T> const& right) {
	return Matrix4x4<T>(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
}

template <typename T>
Matrix4x4<T> operator-(Matrix4x4<T> const& left, Matrix4x4<T> const& right) {
	return Matrix4x4<T>(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
}

template <typename T>
Vector4<T> operator*(Matrix4x4<T> const& left, Vector4<T> const& right) {
	return Vector4<T>(
		left[0][0] * right[0] + left[1][0] * right[1] + left[2][0] * right[2] + left[3][0] * right[3],
		left[0][1] * right[0] + left[1][1] * right[1] + left[2][1] * right[2] + left[3][1] * right[3],
		left[0][2] * right[0] + left[1][2] * right[1] + left[2][2] * right[2] + left[3][2] * right[3],
		left[0][3] * right[0] + left[1][3] * right[1] + left[2][3] * right[2] + left[3][3] * right[3]);
}

template <typename T>
Matrix4x4<T> operator*(Matrix4x4<T> const& left, Matrix4x4<T> const& right) {
	return Matrix4x4<T>(left * right[0], left * right[1], left * right[2], left * right[3]);
}

template <typename T, typename U>
Matrix4x4<T> operator*(Matrix4x4<T> const& left, U right) {
	return Matrix4x4<T>(left[0] * right, left[1] * right, left[2] * right, left[3] * right);
}

template <typename T, typename U>
Matrix4x4<T> operator*(U left, Matrix4x4<T> const& right) {
	return Matrix4x4<T>(left * right[0], left * right[1], left * right[2], left * right[3]);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Matrix4x4<T> const& value) {
	UNUSED(value);
	return os << "Matrix4x4<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Matrix4x4<Float32> const& value) {
	UNUSED(value);
	return os << "Matrix4x4<Float32>";
}

} // namespace engine
