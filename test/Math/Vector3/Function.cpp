// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector3/Function.h"
#include "Math/Vector3/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

namespace  engine {

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
		auto res = math::length(a);
		auto ref = std::sqrt(math::lengthSquared(a));

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;
		ref = std::round(ref * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> normalize(Vector3<T> const& value)") {
		auto res = math::length(math::normalize(a));
		auto ref = 1.0f;

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("T const* getPointer(Vector3<T> const& value)") {
		auto* res = math::getPointer(a);

		REQUIRE(res[0] == 1);
		REQUIRE(res[1] == 2);
		REQUIRE(res[2] == 3);
	}

	SECTION("Vector3<T> invert(Vector3<T> const& value)") {
		auto res = math::invert(a);
		auto ref = Vector3<Float32>(-1, -2, -3);

		REQUIRE(res == ref);
	}
}

} // namespace engine
