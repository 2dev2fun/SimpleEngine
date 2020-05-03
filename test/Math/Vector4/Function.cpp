// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector4/Function.h"
#include "Math/Vector4/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

namespace engine {

TEST_CASE("Math Vector4 Function", "[Vector4 Function]") {
	Vector4<Float32> a(1, 2, 3, 4);
	Vector4<Float32> b(5, 6, 7, 8);

	SECTION("T lengthSquared(Vector4<T> const& value)") {
		auto res = math::lengthSquared(a);
		auto ref = 30;

		REQUIRE(res == ref);
	}

	SECTION("T length(Vector4<T> const& value)") {
		auto res = math::length(a);
		auto ref = std::sqrt(math::lengthSquared(a));

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;
		ref = std::round(ref * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> normalize(Vector4<T> const& value)") {
		auto res = math::length(math::normalize(a));
		auto ref = 1.0f;

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("T const* getPointer(Vector4<T> const& value)") {
		auto* res = math::getPointer(a);

		REQUIRE(res[0] == 1);
		REQUIRE(res[1] == 2);
		REQUIRE(res[2] == 3);
		REQUIRE(res[3] == 4);
	}

	SECTION("Vector4<T> invert(Vector4<T> const& value)") {
		auto res = math::invert(a);
		auto ref = Vector4<Float32>(-1, -2, -3, -4);

		REQUIRE(res == ref);
	}
}

} // namespace engine
