// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix3x3/Function.h"
#include "Math/Matrix3x3/Operator.h"

#include <catch2/catch.hpp>

namespace engine {

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

	SECTION("T const* getPointer(Matrix3x3<T> const& value)") {
		auto* res = math::getPointer(A);

		REQUIRE(res[0] == 1);
		REQUIRE(res[1] == 2);
		REQUIRE(res[2] == 3);
		REQUIRE(res[3] == 1);
		REQUIRE(res[4] == 2);
		REQUIRE(res[5] == 3);
		REQUIRE(res[6] == 1);
		REQUIRE(res[7] == 2);
		REQUIRE(res[8] == 3);
	}
}

} // namespace engine
