// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector3.h"
#include "Math/Vector3/Operator.h"

#include <catch2/catch.hpp>

namespace engine {

TEST_CASE("Math Vector3", "[Vector3]") {
	Vector3<Float32> a(1, 2, 3);
	Vector3<Float32> b(4, 5, 6);

	SECTION("Vector3()") {
		Vector3<Float32> res;
		Vector3<Float32> ref = Vector3<Float32>(0, 0, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector3(T x, T y, T z)") {
		auto res = a;

		REQUIRE(res.x == 1);
		REQUIRE(res.y == 2);
		REQUIRE(res.z == 3);
	}

	SECTION("Vector3(T value)") {
		auto res = Vector3<Float32>(3);

		REQUIRE(res.x == 3);
		REQUIRE(res.y == 3);
		REQUIRE(res.z == 3);
	}
}

} // namespace engine
