// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix4x4/Operator.h"

#include <catch2/catch.hpp>

using namespace engine;

TEST_CASE("Math Matrix4x4 Operator", "[Matrix4x4 Operator]") {
	Vector4<Float32> a( 1,  2,  3,  4);
	Vector4<Float32> b( 5,  6,  7,  8);
	Vector4<Float32> c( 9, 10, 11, 12);
	Vector4<Float32> d(13, 14, 15, 16);

	Matrix4x4<Float32> A(a, a, a, a);
	Matrix4x4<Float32> B(b, b, b, b);

	SECTION("Bool operator==(Matrix4x4<T> const& left, Matrix4x4<T> const& right)") {
		REQUIRE(A == A);
		REQUIRE(B == B);
	}

	SECTION("Bool operator!=(Matrix4x4<T> const& left, Matrix4x4<T> const& right)") {
		REQUIRE(A != B);
		REQUIRE(B != A);
	}

	SECTION("Matrix4x4<T> operator+(Matrix4x4<T> const& left, Matrix4x4<T> const& right)") {
		auto res = A + B;
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(6, 8, 10, 12),
				Vector4<Float32>(6, 8, 10, 12),
				Vector4<Float32>(6, 8, 10, 12),
				Vector4<Float32>(6, 8, 10, 12));

		REQUIRE(res == ref);
	}

	SECTION("Matrix4x4<T> operator-(Matrix4x4<T> const& left, Matrix4x4<T> const& right)") {
		auto res = A - B;
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(-4, -4, -4, -4),
				Vector4<Float32>(-4, -4, -4, -4),
				Vector4<Float32>(-4, -4, -4, -4),
				Vector4<Float32>(-4, -4, -4, -4));

		REQUIRE(res == ref);
	}

	SECTION("Vector4<T> operator*(Matrix4x4<T> const& left, Vector4<T> const& right)") {
		auto res = A * b;
		auto ref = Vector4<Float32>(26, 52, 78, 104);

		REQUIRE(res == ref);
	}

	SECTION("Matrix4x4<T> operator*(Matrix4x4<T> const& left, Matrix4x4<T> const& right)") {
		auto res = A * B;
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(26, 52, 78, 104),
				Vector4<Float32>(26, 52, 78, 104),
				Vector4<Float32>(26, 52, 78, 104),
				Vector4<Float32>(26, 52, 78, 104));

		REQUIRE(res == ref);
	}

	SECTION("Matrix4x4<T> operator*(Matrix4x4<T> const& left, U right)") {
		auto res = A * 2;
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8));

		REQUIRE(res == ref);
	}

	SECTION("Matrix4x4<T> operator*(U left, Matrix4x4<T> const& right)") {
		auto res = 2 * A;
		auto ref = Matrix4x4<Float32>(
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8),
				Vector4<Float32>(2, 4, 6, 8));

		REQUIRE(res == ref);
	}
}
