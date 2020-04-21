// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

template<typename T>
class Quaternion {
public:
	Quaternion();
	Quaternion(T x, T y, T z, T w = 1);

	T x;
	T y;
	T z;
	T w;
};

template <typename T>
Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(1) {}

template <typename T>
Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

} // namespace engine
