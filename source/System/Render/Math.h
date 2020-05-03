// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

namespace engine {
namespace math {

Mat4 lookAt(Vec3 const& eye, Vec3 const& target, Vec3 const& up);
Mat4 perspective(Float32 fov, Float32 widht, Float32 height, Float32 near, Float32 far);
Vec3 transform(Vec3 const& vector, Quat const& rotation);
Mat4 createTranslation(Vec3 const& translation);
Mat4 createRotation(Quat const& rotation);
Mat4 createScale(Float32 scale);

} // namespace math
} // namespace engine
