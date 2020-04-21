// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector3/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Vector3 Operator", "[Vector3 Operator]") {
	Vector3<Float32> a(1, 2, 5);
	Vector3<Float32> b(4, 5, 6);

	SECTION("Bool operator==(const Vector3<T>& left, const Vector3<T>& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("Bool operator!=(const Vector3<T>& left, const Vector3<T>& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}

	SECTION("Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)") {
		auto res = a + b;
		auto ref = Vector3<Float32>(5, 7, 9);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)") {
		auto res = a - b;
		auto ref = Vector3<Float32>(-3, -3, -3);

		REQUIRE(res == ref);
	}

	SECTION("T operator*(const Vector3<T>& left, const Vector3<T>& right)") {
		auto res = a * b;
		auto ref = 32;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator+(const Vector3<T>& left, U right)") {
		auto res = a + 3;
		auto ref = Vector3<Float32>(4, 5, 6);

		REQUIRE(res == ref);
	}


	SECTION("Vector3<T> operator-(const Vector3<T>& left, U right)") {
		auto res = a - 3;
		auto ref = Vector3<Float32>(-2, -1, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator*(const Vector3<T>& left, U right)") {
		auto res = a * 2;
		auto ref = Vector3<Float32>(2, 4, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator+(U left, const Vector3<T>& right)") {
		auto res = 3 + a;
		auto ref = Vector3<Float32>(4, 5, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator-(U left, const Vector3<T>& right)") {
		auto res = 3 - a;
		auto ref = Vector3<Float32>(2, 1, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator*(U left, const Vector3<T>& right)") {
		auto res = 2 * a;
		auto ref = Vector3<Float32>(2, 4, 6);

		REQUIRE(res == ref);
	}
}
