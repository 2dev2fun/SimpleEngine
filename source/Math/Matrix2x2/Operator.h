// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix2x2.h"
#include "Math/Vector2/Operator.h"

#include <ostream>

namespace engine {

template <typename T>
Bool operator==(Matrix2x2<T> const& left, Matrix2x2<T> const& right) {
	return left[0] == right[0] && left[1] == right[1];
}

template <typename T>
Bool operator!=(Matrix2x2<T> const& left, Matrix2x2<T> const& right) {
	return !(left == right);
}

template <typename T>
Matrix2x2<T> operator+(Matrix2x2<T> const& left, Matrix2x2<T> const& right) {
	return Matrix2x2<T>(left[0] + right[0], left[1] + right[1]);
}

template <typename T>
Matrix2x2<T> operator-(Matrix2x2<T> const& left, Matrix2x2<T> const& right) {
	return Matrix2x2<T>(left[0] - right[0], left[1] - right[1]);
}

template <typename T>
Vector2<T> operator*(Matrix2x2<T> const& left, Vector2<T> const& right) {
	return Vector2<T>(
		left[0][0] * right[0] + left[1][0] * right[1],
		left[0][1] * right[0] + left[1][1] * right[1]);
}

template <typename T>
Matrix2x2<T> operator*(Matrix2x2<T> const& left, Matrix2x2<T> const& right) {
	return Matrix2x2<T>(left * right[0], left * right[1]);
}

template <typename T, typename U>
Matrix2x2<T> operator*(Matrix2x2<T> const& left, U right) {
	return Matrix2x2<T>(left[0] * right, left[1] * right);
}

template <typename T, typename U>
Matrix2x2<T> operator*(U left, Matrix2x2<T> const& right) {
	return Matrix2x2<T>(left * right[0], left * right[1]);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Matrix2x2<T> const& value) {
	UNUSED(value);
	return os << "Matrix2x2<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Matrix2x2<Float32> const& value) {
	UNUSED(value);
	return os << "Matrix2x2<Float32>";
}

} // namespace engine
