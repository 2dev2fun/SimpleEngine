// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix4x4/Function.h"
#include "Math/Matrix4x4/Operator.h"

#include <catch2/catch.hpp>

namespace engine {

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

	SECTION("T const* getPointer(Matrix3x3<T> const& value)") {
		auto* res = math::getPointer(A);

		REQUIRE(res[0]  == 1);
		REQUIRE(res[1]  == 2);
		REQUIRE(res[2]  == 3);
		REQUIRE(res[3]  == 4);
		REQUIRE(res[4]  == 1);
		REQUIRE(res[5]  == 2);
		REQUIRE(res[6]  == 3);
		REQUIRE(res[7]  == 4);
		REQUIRE(res[8]  == 1);
		REQUIRE(res[9]  == 2);
		REQUIRE(res[10] == 3);
		REQUIRE(res[11] == 4);
		REQUIRE(res[12] == 1);
		REQUIRE(res[13] == 2);
		REQUIRE(res[14] == 3);
		REQUIRE(res[15] == 4);
	}
}

} // namespace engine
