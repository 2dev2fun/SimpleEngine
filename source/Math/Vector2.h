// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

template<typename T>
class Vector2 {
public:
	Vector2();
	Vector2(T x, T y);
	explicit Vector2(T value);

	T& operator[](UInt32 index);
	T const& operator[](UInt32 index) const;

	template <typename U>
	Vector2<T>& operator+=(U right);

	template <typename U>
	Vector2<T>& operator-=(U right);

	template <typename U>
	Vector2<T>& operator*=(U right);

	T x;
	T y;
};

template <typename T>
Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <typename T>
Vector2<T>::Vector2(T value) : x(value), y(value) {}

template <typename T>
T& Vector2<T>::operator[](UInt32 index) {
	return *(&x + index);
}

template <typename T>
T const& Vector2<T>::operator[](UInt32 index) const {
	return *(&x + index);
}

template <typename T>
template <typename U>
Vector2<T>& Vector2<T>::operator+=(U right) {
	x += right;
	y += right;
	return *this;
}

template <typename T>
template <typename U>
Vector2<T>& Vector2<T>::operator-=(U right) {
	x -= right;
	y -= right;
	return *this;
}

template <typename T>
template <typename U>
Vector2<T>& Vector2<T>::operator*=(U right) {
	x *= right;
	y *= right;
	return *this;
}

} // namespace engine
