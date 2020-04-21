// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector2.h"

namespace engine {

template <typename T>
class Matrix2x2 {
public:
	Matrix2x2();
	Matrix2x2(Vector2<T> const& x, Vector2<T> const& y);

	Vector2<T>& operator[](UInt32 column);
	Vector2<T> const& operator[](UInt32 column) const;
private:
	Vector2<T> mColumns[2];
};

template <typename T>
Matrix2x2<T>::Matrix2x2() {
	mColumns[0] = Vector2<T>(1, 0);
	mColumns[1] = Vector2<T>(0, 1);
}

template <typename T>
Matrix2x2<T>::Matrix2x2(Vector2<T> const& x, Vector2<T> const& y) {
	mColumns[0] = x;
	mColumns[1] = y;
}

template <typename T>
Vector2<T>& Matrix2x2<T>::operator[](UInt32 column) {
	return mColumns[column];
}

template <typename T>
Vector2<T> const& Matrix2x2<T>::operator[](UInt32 column) const {
	return mColumns[column];
}

} // namespace engine
