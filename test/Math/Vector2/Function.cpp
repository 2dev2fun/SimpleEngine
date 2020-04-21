// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector2/Function.h"
#include "Math/Vector2/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

using namespace engine;

TEST_CASE("Math Vector2 Function", "[Vector2 Function]") {
	Vector2<Float32> a(1, 2);
	Vector2<Float32> b(3, 4);

	SECTION("T lengthSquared(Vector2<T> const& value)") {
		auto res = math::lengthSquared(a);
		auto ref = 5;

		REQUIRE(res == ref);
	}

	SECTION("T length(Vector2<T> const& value)") {
		auto res = math::length(a);
		auto ref = std::sqrt(math::lengthSquared(a));

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;
		ref = std::round(ref * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> normalize(Vector2<T> const& value)") {
		auto res = math::length(math::normalize(a));
		auto ref = 1.0f;

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}
}
