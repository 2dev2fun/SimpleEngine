// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix2x2/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix2x2 Operator", "[Matrix2x2 Operator]") {
	Vector2<Float32> a(1, 2);
	Vector2<Float32> b(3, 4);

	Matrix2x2<Float32> A(a, a);
	Matrix2x2<Float32> B(b, b);

	SECTION("Bool operator==(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		REQUIRE(A == A);
		REQUIRE(B == B);
	}

	SECTION("Bool operator!=(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		REQUIRE(A != B);
		REQUIRE(B != A);
	}

	SECTION("Matrix2x2<T> operator+(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A + B;
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(4, 6),
				Vector2<Float32>(4, 6));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator-(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A - B;
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(-2, -2),
				Vector2<Float32>(-2, -2));

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator*(Matrix2x2<T> const& left, Vector2<T> const& right)") {
		auto res = A * b;
		auto ref = Vector2<Float32>(7, 14);

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A * B;
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(7, 14),
				Vector2<Float32>(7, 14));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(Matrix2x2<T> const& left, U right)") {
		auto res = A * 2;
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(2, 4),
				Vector2<Float32>(2, 4));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(U left, Matrix2x2<T> const& right)") {
		auto res = 2 * A;
		auto ref = Matrix2x2<Float32>(
				Vector2<Float32>(2, 4),
				Vector2<Float32>(2, 4));

		REQUIRE(res == ref);
	}
}
