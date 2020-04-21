// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector3/Function.h"
#include "Math/Vector3/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

using namespace engine;

TEST_CASE("Math Vector3 Function", "[Vector3 Function]") {
	Vector3<Float32> a(1, 2, 3);
	Vector3<Float32> b(4, 5, 6);

	SECTION("Vector3<T> cross(Vector3<T> const& left, Vector3<T> const& right)") {
		auto res = math::cross(a, b);
		auto ref = Vector3<Float32>(-3, 6, -3);

		REQUIRE(res == ref);
	}

	SECTION("T lengthSquared(Vector3<T> const& value)") {
		auto res = math::lengthSquared(a);
		auto ref = 14;

		REQUIRE(res == ref);
	}

	SECTION("T length(Vector3<T> const& value)") {
		Vector3<Float32> c(2, 4, 4);

		auto res = math::length(c);
		auto ref = 6;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> normalize(Vector3<T> const& value)") {
		Float32 res = math::length(math::normalize(a));
		Float32 ref = 1.0f;

		res = std::round(res * 1000.0f) / 1000.0f;

		REQUIRE(res == ref);
	}
}
