// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine/Forward.h"

#include <cstdint>

namespace engine {

using Char = char;
using Bool = bool;

using Int8  = std::int8_t;
using Int16 = std::int16_t;
using Int32 = std::int32_t;
using Int64 = std::int64_t;

using UInt8  = std::uint8_t;
using UInt16 = std::uint16_t;
using UInt32 = std::uint32_t;
using UInt64 = std::uint64_t;

using Float32 = float;
using Float64 = double;

using Mat2 = Matrix2x2<Float32>;
using Mat3 = Matrix3x3<Float32>;
using Mat4 = Matrix4x4<Float32>;

using Quat = Quaternion<Float32>;

using Vec2 = Vector2<Float32>;
using Vec3 = Vector3<Float32>;
using Vec4 = Vector4<Float32>;

using Entity = UInt32;
using Index  = UInt32;
using Mask   = UInt64;

} // namespace engine
