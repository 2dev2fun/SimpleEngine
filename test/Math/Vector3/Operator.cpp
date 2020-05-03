// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector3/Operator.h"

#include <catch2/catch.hpp>

namespace engine {

TEST_CASE("Math Vector3 Operator", "[Vector3 Operator]") {
	Vector3<Float32> a(1, 2, 3);
	Vector3<Float32> b(4, 5, 6);

	SECTION("Vector3<T>& operator+=(Vector3<T>& left, U right)") {
		auto res = a;
		res += 3;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T>& operator-=(Vector3<T>& left, U right)") {
		auto res = b;
		res -= 3;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T>& operator*=(Vector3<T>& left, U right)") {
		auto res = a;
		res *= 2;
		auto ref = Vector3<Float32>(2, 4, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T>& operator+=(Vector3<T>& left, Vector3<T> const& right)") {
		auto res = a;
		res += b;
		auto ref = Vector3<Float32>(5, 7, 9);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T>& operator-=(Vector3<T>& left, Vector3<T> const& right)") {
		auto res = a;
		res -= b;
		auto ref = Vector3<Float32>(-3, -3, -3);

		REQUIRE(res == ref);
	}

	SECTION("Bool operator==(Vector3<T> const& left, Vector3<T> const& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("Bool operator!=(Vector3<T> const& left, Vector3<T> const& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}

	SECTION("Vector3<T> operator+(Vector3<T> const& left, Vector3<T> const& right)") {
		auto res = a + b;
		auto ref = Vector3<Float32>(5, 7, 9);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator-(Vector3<T> const& left, Vector3<T> const& right)") {
		auto res = a - b;
		auto ref = Vector3<Float32>(-3, -3, -3);

		REQUIRE(res == ref);
	}

	SECTION("T operator*(Vector3<T> const& left, Vector3<T> const& right)") {
		auto res = a * b;
		auto ref = 32;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator+(Vector3<T> const& left, U right)") {
		auto res = a + 3;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator-(Vector3<T> const& left, U right)") {
		auto res = b - 3;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator*(Vector3<T> const& left, U right)") {
		auto res = a * 2;
		auto ref = Vector3<Float32>(2, 4, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator+(U left, Vector3<T> const& right)") {
		auto res = 3 + a;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator*(U left, Vector3<T> const& right)") {
		auto res = 2 * a;
		auto ref = Vector3<Float32>(2, 4, 6);

		REQUIRE(res == ref);
	}
}

} // namespace engine
