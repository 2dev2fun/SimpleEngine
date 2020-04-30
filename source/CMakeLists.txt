# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

project(Engine)

add_library(EngineLib
	"Command.cpp"
	"Command/Exit.cpp"
	"Command/Test.cpp"
	"Component/Mesh.cpp"
	"Component/Transform3D.cpp"
	"Game.cpp"
	"Manager/Mesh.cpp"
	"Manager/Texture.cpp"
	"System/Input.cpp"
	"System/Render.cpp"
	"System/Render/Backend/OpenGL/Shader.cpp"
	"System/Render/Backend/OpenGL/Shader/Mesh.cpp"
	"System/Render/Backend/OpenGL/Texture.cpp"
	"System/Render/Backend/OpenGL/VertexArray.cpp"
	"System/Render/Mesh.cpp"
	"System/Render/Primitive.cpp"
	"System/Render/Technique/Mesh.cpp"
	"System/Window.cpp"
	"System/World.cpp"
	"Utility/Base64.cpp"
	"Utility/GLTF2.cpp"
	"Utility/GLTF2/Accessor.cpp"
	"Utility/GLTF2/Animation.cpp"
	"Utility/GLTF2/Asset.cpp"
	"Utility/GLTF2/Mesh.cpp"
	"Utility/GLTF2/Node.cpp"
	"Utility/Image.cpp")

target_link_libraries(EngineLib glad)
target_link_libraries(EngineLib glfw)

target_link_libraries(ProjectLib INTERFACE EngineLib)
