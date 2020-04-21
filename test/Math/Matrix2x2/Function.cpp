// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix2x2/Function.h"
#include "Math/Matrix2x2/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix2x2 Function", "[Matrix2x2 Function]") {
	Vector2<Float32> a(1, 2);
	Vector2<Float32> b(3, 4);

	Matrix2x2<Float32> A(a, a);
	Matrix2x2<Float32> B(b, b);

	SECTION("Matrix2x2<T> transpose(Matrix2x2<T> const& value)") {
		auto res = math::transpose(A);
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(1, 1),
				Vector2<Float32>(2, 2));

		REQUIRE(res == ref);
	}
}
