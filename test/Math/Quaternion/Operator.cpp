// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Quaternion/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Quaternion Operator", "[Quaternion Operator]") {
	Quaternion<Float32> a(1, 2, 3, 4);
	Quaternion<Float32> b(5, 6, 7, 8);

	SECTION("Bool operator==(Quaternion<T> const& left, Quaternion<T> const& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("Bool operator!=(Quaternion<T> const& left, Quaternion<T> const& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}
}
