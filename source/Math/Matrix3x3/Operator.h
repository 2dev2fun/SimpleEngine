// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix3x3.h"
#include "Math/Vector3/Operator.h"

#include <ostream>

namespace engine {

template <typename T>
Bool operator==(Matrix3x3<T> const& left, Matrix3x3<T> const& right) {
	return left[0] == right[0] && left[1] == right[1] && left[2] == right[2];
}

template <typename T>
Bool operator!=(Matrix3x3<T> const& left, Matrix3x3<T> const& right) {
	return !(left == right);
}

template <typename T>
Matrix3x3<T> operator+(Matrix3x3<T> const& left, Matrix3x3<T> const& right) {
	return Matrix3x3<T>(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
}

template <typename T>
Matrix3x3<T> operator-(Matrix3x3<T> const& left, Matrix3x3<T> const& right) {
	return Matrix3x3<T>(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
}

template <typename T>
Vector3<T> operator*(Matrix3x3<T> const& left, Vector3<T> const& right) {
	return Vector3<T>(
		left[0][0] * right[0] + left[1][0] * right[1] + left[2][0] * right[2],
		left[0][1] * right[0] + left[1][1] * right[1] + left[2][1] * right[2],
		left[0][2] * right[0] + left[1][2] * right[1] + left[2][2] * right[2]);
}

template <typename T>
Matrix3x3<T> operator*(Matrix3x3<T> const& left, Matrix3x3<T> const& right) {
	return Matrix3x3<T>(left * right[0], left * right[1], left * right[2]);
}

template <typename T, typename U>
Matrix3x3<T> operator*(Matrix3x3<T> const& left, U right) {
	return Matrix3x3<T>(left[0] * right, left[1] * right, left[2] * right);
}

template <typename T, typename U>
Matrix3x3<T> operator*(U left, Matrix3x3<T> const& right) {
	return Matrix3x3<T>(left * right[0], left * right[1], left * right[2]);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Matrix3x3<T> const& value) {
	UNUSED(value);
	return os << "Matrix3x3<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Matrix3x3<Float32> const& value) {
	UNUSED(value);
	return os << "Matrix3x3<Float32>";
}

} // namespace engine
