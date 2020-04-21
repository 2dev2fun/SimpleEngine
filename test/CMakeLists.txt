# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

add_executable(Test
	"Main.cpp"
	"Math/Matrix2x2.cpp"
	"Math/Matrix2x2/Function.cpp"
	"Math/Matrix2x2/Operator.cpp"
	"Math/Matrix3x3.cpp"
	"Math/Matrix3x3/Function.cpp"
	"Math/Matrix3x3/Operator.cpp"
	"Math/Matrix4x4.cpp"
	"Math/Matrix4x4/Function.cpp"
	"Math/Matrix4x4/Operator.cpp"
	"Math/Quaternion.cpp"
	"Math/Quaternion/Function.cpp"
	"Math/Quaternion/Operator.cpp"
	"Math/Vector2.cpp"
	"Math/Vector2/Function.cpp"
	"Math/Vector2/Operator.cpp"
	"Math/Vector3.cpp"
	"Math/Vector3/Function.cpp"
	"Math/Vector3/Operator.cpp"
	"Math/Vector4.cpp"
	"Math/Vector4/Function.cpp"
	"Math/Vector4/Operator.cpp")

target_link_libraries(Test ProjectLib)
