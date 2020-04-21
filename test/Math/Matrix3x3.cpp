// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix3x3.h"
#include "Math/Matrix3x3/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix3x3", "[Matrix3x3]") {
	Vector3<Float32> a(1, 2, 3);
	Vector3<Float32> b(4, 5, 6);

	SECTION("Matrix3x3()") {
		auto a = Vector3<Float32>(1, 0, 0);
		auto b = Vector3<Float32>(0, 1, 0);
		auto c = Vector3<Float32>(0, 0, 1);

		Matrix3x3<Float32> res;

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
	}

	SECTION("Matrix3x3(Vector3<T> const& x, Vector3<T> const& y, Vector3<T> const& z)") {
		auto a = Vector3<Float32>(1, 2, 3);
		auto b = Vector3<Float32>(4, 5, 6);
		auto c = Vector3<Float32>(7, 8, 9);

		Matrix3x3<Float32> res(a, b, c);

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
	}
}
