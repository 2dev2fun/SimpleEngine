# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

project(Engine)

add_library(EngineLib
	"Command.cpp"
	"Command/Exit.cpp"
	"Command/Test.cpp"
	"Component/Mesh.cpp"
	"Component/Transform3D.cpp"
	"Game.cpp"
	"System/Input.cpp"
	"System/Render.cpp"
	"System/Render/Backend/OpenGL/Shader.cpp"
	"System/Render/Backend/OpenGL/Shader/Mesh.cpp"
	"System/Render/Backend/OpenGL/VertexArray.cpp"
	"System/Render/Technique/Mesh.cpp"
	"System/Window.cpp"
	"System/World.cpp")

target_link_libraries(EngineLib glad)
target_link_libraries(EngineLib glfw)

target_link_libraries(ProjectLib INTERFACE EngineLib)
