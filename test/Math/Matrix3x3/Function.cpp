// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix3x3/Function.h"
#include "Math/Matrix3x3/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix3x3 Function", "[Matrix3x3 Function]") {
	Vector3<Float32> a(1, 2, 3);
	Vector3<Float32> b(4, 5, 6);

	Matrix3x3<Float32> A(a, a, a);
	Matrix3x3<Float32> B(b, b, b);

	SECTION("Matrix3x3<T> transpose(Matrix3x3<T> const& value)") {
		auto res = math::transpose(A);
		auto ref = Matrix3x3<Float32>(
				Vector3<Float32>(1, 1, 1),
				Vector3<Float32>(2, 2, 2),
				Vector3<Float32>(3, 3, 3));

		REQUIRE(res == ref);
	}
}
