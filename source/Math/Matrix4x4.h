// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector4.h"

namespace engine {

template <typename T>
class Matrix4x4 {
public:
	Matrix4x4();
	Matrix4x4(Vector4<T> const& x, Vector4<T> const& y, Vector4<T> const& z, Vector4<T> const& w);

	Vector4<T>& operator[](UInt32 column);
	Vector4<T> const& operator[](UInt32 column) const;
private:
	Vector4<T> mColumns[4];
};

template <typename T>
Matrix4x4<T>::Matrix4x4() {
	mColumns[0] = Vector4<T>(1, 0, 0, 0);
	mColumns[1] = Vector4<T>(0, 1, 0, 0);
	mColumns[2] = Vector4<T>(0, 0, 1, 0);
	mColumns[3] = Vector4<T>(0, 0, 0, 1);
}

template <typename T>
Matrix4x4<T>::Matrix4x4(Vector4<T> const& x, Vector4<T> const& y, Vector4<T> const& z, Vector4<T> const& w) {
	mColumns[0] = x;
	mColumns[1] = y;
	mColumns[2] = z;
	mColumns[3] = w;
}

template <typename T>
Vector4<T>& Matrix4x4<T>::operator[](UInt32 column) {
	return mColumns[column];
}

template <typename T>
Vector4<T> const& Matrix4x4<T>::operator[](UInt32 column) const {
	return mColumns[column];
}

} // namespace engine
