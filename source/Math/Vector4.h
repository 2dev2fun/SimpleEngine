// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

template<typename T>
class Vector4 {
public:
	Vector4();
	Vector4(T x, T y, T z, T w);
	explicit Vector4(T value);

	T& operator[](UInt32 index);
	T const& operator[](UInt32 index) const;

	template <typename U>
	Vector4<T>& operator+=(U right);

	template <typename U>
	Vector4<T>& operator-=(U right);

	template <typename U>
	Vector4<T>& operator*=(U right);

	T x;
	T y;
	T z;
	T w;
};

template <typename T>
Vector4<T>::Vector4() : x(0), y(0), z(0), w(0) {}

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

template <typename T>
Vector4<T>::Vector4(T value) : x(value), y(value), z(value), w(value) {}

template <typename T>
T& Vector4<T>::operator[](UInt32 index) {
	return *(&x + index);
}

template <typename T>
T const& Vector4<T>::operator[](UInt32 index) const {
	return *(&x + index);
}

template <typename T>
template <typename U>
Vector4<T>& Vector4<T>::operator+=(U right) {
	x += right;
	y += right;
	z += right;
	w += right;
	return *this;
}

template <typename T>
template <typename U>
Vector4<T>& Vector4<T>::operator-=(U right) {
	x -= right;
	y -= right;
	z -= right;
	w -= right;
	return *this;
}

template <typename T>
template <typename U>
Vector4<T>& Vector4<T>::operator*=(U right) {
	x *= right;
	y *= right;
	z *= right;
	w *= right;
	return *this;
}

} // namespace engine
