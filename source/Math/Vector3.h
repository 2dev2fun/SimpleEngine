// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

template<typename T>
class Vector3 {
public:
	Vector3();
	Vector3(T x, T y, T z);
	explicit Vector3(T value);

	T& operator[](UInt32 index);
	T const& operator[](UInt32 index) const;

	T x;
	T y;
	T z;
};

template <typename T>
Vector3<T>::Vector3() : x(0), y(0), z(0) {}

template <typename T>
Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

template <typename T>
Vector3<T>::Vector3(T value) : x(value), y(value), z(value) {}

template <typename T>
T& Vector3<T>::operator[](UInt32 index) {
	return *(&x + index);
}

template <typename T>
T const& Vector3<T>::operator[](UInt32 index) const {
	return *(&x + index);
}

} // namespace engine
