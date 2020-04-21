# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

add_executable(Test
	"Main.cpp"
	"Math/Matrix3x3.cpp"
	"Math/Matrix3x3/Function.cpp"
	"Math/Matrix3x3/Operator.cpp"
	"Math/Vector3.cpp"
	"Math/Vector3/Function.cpp"
	"Math/Vector3/Operator.cpp")

target_link_libraries(Test ProjectLib)
