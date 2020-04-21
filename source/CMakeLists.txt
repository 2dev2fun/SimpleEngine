# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

project(Engine)

add_library(EngineLib
	"Command.cpp"
	"Command/Exit.cpp"
	"Command/Test.cpp"
	"Game.cpp"
	"System/Input.cpp"
	"System/Window.cpp")

target_link_libraries(EngineLib glfw)
target_link_libraries(EngineLib glad)

target_link_libraries(ProjectLib INTERFACE EngineLib)
