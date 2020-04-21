// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix4x4/Function.h"
#include "Math/Matrix4x4/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix4x4 Function", "[Matrix4x4 Function]") {
	Vector4<Float32> a( 1,  2,  3,  4);
	Vector4<Float32> b( 5,  6,  7,  8);
	Vector4<Float32> c( 9, 10, 11, 12);
	Vector4<Float32> d(13, 14, 15, 16);

	Matrix4x4<Float32> A(a, a, a, a);
	Matrix4x4<Float32> B(b, b, b, b);

	SECTION("Matrix4x4<T> transpose(Matrix4x4<T> const& value)") {
		auto res = math::transpose(A);
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(1, 1, 1, 1),
				Vector4<Float32>(2, 2, 2, 2),
				Vector4<Float32>(3, 3, 3, 3),
				Vector4<Float32>(4, 4, 4, 4));

		REQUIRE(res == ref);
	}
}
