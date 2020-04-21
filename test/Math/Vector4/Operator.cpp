// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector4/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Vector4 Operator", "[Vector4 Operator]") {
	Vector4<Float32> a(1, 2, 3, 4);
	Vector4<Float32> b(5, 6, 7, 8);

	SECTION("Bool operator==(Vector4<T> const& left, Vector4<T> const& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("Bool operator!=(Vector4<T> const& left, Vector4<T> const& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}

	SECTION("Vector4<T> operator+(Vector4<T> const& left, Vector4<T> const& right)") {
		auto res = a + b;
		auto ref = Vector4<Float32>(6, 8, 10, 12);

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator-(Vector4<T> const& left, Vector4<T> const& right)") {
		auto res = a - b;
		auto ref = Vector4<Float32>(-4, -4, -4, -4);

		REQUIRE(res == ref);
	}

	SECTION("T operator*(Vector4<T> const& left, Vector4<T> const& right)") {
		auto res = a * b;
		auto ref = 70;

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator+(Vector4<T> const& left, U right)") {
		auto res = a + 4;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator-(Vector4<T> const& left, U right)") {
		auto res = b - 4;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator*(Vector4<T> const& left, U right)") {
		auto res = a * 2;
		auto ref = Vector4<Float32>(2, 4, 6, 8);

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator+(U left, Vector4<T> const& right)") {
		auto res = 4 + a;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator*(U left, Vector4<T> const& right)") {
		auto res = 2 * a;
		auto ref = Vector4<Float32>(2, 4, 6, 8);

		REQUIRE(res == ref);
	}
}
