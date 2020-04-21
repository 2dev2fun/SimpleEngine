// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix2x2.h"

namespace engine {
namespace math {

template <typename T>
Matrix2x2<T> transpose(Matrix2x2<T> const& value) {
	return Matrix2x2<T>(
			Vector2<T>(value[0][0], value[1][0]),
			Vector2<T>(value[0][1], value[1][1]));
}

} // namespace math
} // namespace engine
