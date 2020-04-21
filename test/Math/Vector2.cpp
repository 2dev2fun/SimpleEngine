// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector2.h"
#include "Math/Vector2/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Vector2", "[Vector2]") {
	Vector2<Float32> a(1, 2);
	Vector2<Float32> b(3, 4);

	SECTION("Vector2()") {
		Vector2<Float32> res;
		Vector2<Float32> ref = Vector2<Float32>(0, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector2(T x, T y)") {
		auto res = a;

		REQUIRE(res.x == 1);
		REQUIRE(res.y == 2);
	}

	SECTION("Vector2(T value)") {
		auto res = Vector2<Float32>(3);

		REQUIRE(res.x == 3);
		REQUIRE(res.y == 3);
	}

	SECTION("Vector2<T>& operator+=(U right)") {
		auto res = a;
		res += 2;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator-=(U right)") {
		auto res = b;
		res -= 2;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator*=(U right)") {
		auto res = a;
		res *= 2;
		auto ref = Vector2<Float32>(2, 4);

		REQUIRE(res == ref);
	}
}
