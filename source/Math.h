// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

#include <cmath>

namespace engine {
namespace math {

inline extern Float32 const PI         = 3.141592f;
inline extern Float32 const TWO_PI     = PI / 2.0f;

inline extern Vec3 const RIGHT   { 1.0f, 0.0f,  0.0f };
inline extern Vec3 const UP      { 0.0f, 1.0f,  0.0f };
inline extern Vec3 const FORWARD { 0.0f, 0.0f, -1.0f };

template <typename T>
T max(T const& a, T const& b) {
	return a < b ? b : a;
}

template <typename T>
T min(T const& a, T const& b) {
	return a < b ? a : b;
}

template <typename T>
T power(T base, T exponent) {
	return std::pow(base, exponent);
}

inline Float32 abs(Float32 value) {
	return std::fabs(value);
}

inline Float32 cos(Float32 value) {
	return std::cos(value);
}

inline Float32 sin(Float32 value) {
	return std::sin(value);
}

inline Float32 tan(Float32 value) {
	return std::tan(value);
}

inline Float32 cot(Float32 value) {
	return 1.0f / tan(value);
}

inline Float32 acos(Float32 value) {
	return std::acos(value);
}

inline Float32 asin(Float32 value) {
	return std::asin(value);
}

inline Float32 sqrt(Float32 value) {
	return std::sqrt(value);
}

inline Float32 fmod(Float32 numer, Float32 denom) {
	return std::fmod(numer, denom);
}

inline Float32 atan2(Float32 y, Float32 x) {
	return std::atan2(y, x);
}

inline Float32 clamp(Float32 value, Float32 lower, Float32 upper) {
	return min(upper, max(lower, value));
}

inline Float32 lerp(Float32 previous, Float32 next, Float32 fraction) {
	return previous + fraction * (next - previous);
}

inline Bool nearZero(Float32 value, Float32 epsilon = 0.001f) {
	return abs(value) <= epsilon ? true : false;
}

inline Float32 toRadians(Float32 degrees) {
	return degrees * PI / 180.0f;
}

inline Float32 toDegrees(Float32 radians) {
	return radians * 180.0f / PI;
}

} // namespace math
} // namespace engine
