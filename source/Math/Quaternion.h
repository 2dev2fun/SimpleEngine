// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

#include <cmath>

namespace engine {

template<typename T>
class Quaternion {
public:
	Quaternion();
	Quaternion(T x, T y, T z, T w = 1);
	Quaternion(Vector3<T> const& axis, T angle);

	T& operator[](UInt32 index);
	T const& operator[](UInt32 index) const;

	T x;
	T y;
	T z;
	T w;
};

template <typename T>
Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(1) {}

template <typename T>
Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

template <typename T>
Quaternion<T>::Quaternion(Vector3<T> const& axis, T angle) {
	T scalar = std::sin(angle / 2.0f);
	x = axis.x * scalar;
	y = axis.y * scalar;
	z = axis.z * scalar;
	w = std::cos(angle / 2.0f);
}

template <typename T>
T& Quaternion<T>::operator[](UInt32 index) {
	return *(&x + index);
}

template <typename T>
T const& Quaternion<T>::operator[](UInt32 index) const {
	return *(&x + index);
}

} // namespace engine
