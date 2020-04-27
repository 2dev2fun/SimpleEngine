// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

namespace engine {

// Math -----------------------------------------------------------------------

template <typename T>
class Matrix2x2;

template <typename T>
class Matrix3x3;

template <typename T>
class Matrix4x4;

template <typename T>
class Quaternion;

template <typename T>
class Vector2;

template <typename T>
class Vector3;

template <typename T>
class Vector4;

// General --------------------------------------------------------------------

class Command;
class Game;

// InputSystem ----------------------------------------------------------------

class InputSystem;

// RenderSystem ---------------------------------------------------------------

class RenderSystem;

class Shader;
class MeshShader;

class MeshTechnique;

// WindowSystem ---------------------------------------------------------------

class WindowSystem;

// WorldSystem ----------------------------------------------------------------

class WorldSystem;

class MeshComponent;
class Transform3DComponent;

template <typename Component>
class Table;

} // namespace engine
