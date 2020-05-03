// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Quaternion/Function.h"
#include "Math/Quaternion/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

namespace engine {

TEST_CASE("Math Quaternion Function", "[Quaternion Function]") {
	Quaternion<Float32> a(1, 2, 3, 4);
	Quaternion<Float32> b(5, 6, 7, 8);

	SECTION("T lengthSquared(Quaternion<T> const& value)") {
		auto res = math::lengthSquared(a);
		auto ref = 30;

		REQUIRE(res == ref);
	}

	SECTION("T length(Quaternion<T> const& value)") {
		auto res = math::length(a);
		auto ref = std::sqrt(math::lengthSquared(a));

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;
		ref = std::round(ref * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Quaternion<T> normalize(Quaternion<T> const& value)") {
		auto res = math::length(math::normalize(a));
		auto ref = 1.0f;

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Quaternion<T> conjugate(Quaternion<T> const& value)") {
		auto res = math::conjugate(a);
		auto ref = Quaternion<Float32>(-a.x, -a.y, -a.z, a.w);

		REQUIRE(res == ref);
	}
}

} // namespace engine
