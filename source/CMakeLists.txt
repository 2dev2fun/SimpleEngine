# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

project(Engine)

add_library(EngineLib
	"Command.cpp"
	"Command/Exit.cpp"
	"Command/Test.cpp"
	"Command/PlayerBackward.cpp"
	"Command/PlayerForward.cpp"
	"Command/PlayerLeft.cpp"
	"Command/PlayerOverviewStart.cpp"
	"Command/PlayerOverviewStop.cpp"
	"Command/PlayerRight.cpp"
	"Command/PlayerRotation.cpp"
	"Component/Mesh.cpp"
	"Component/Move.cpp"
	"Component/Transform3D.cpp"
	"Game.cpp"
	"Manager/Mesh.cpp"
	"Manager/Texture.cpp"
	"System/Input.cpp"
	"System/Movement.cpp"
	"System/Render.cpp"
	"System/Render/Backend/OpenGL/Shader.cpp"
	"System/Render/Backend/OpenGL/Shader/Mesh.cpp"
	"System/Render/Backend/OpenGL/Texture.cpp"
	"System/Render/Backend/OpenGL/VertexArray.cpp"
	"System/Render/Camera.cpp"
	"System/Render/Camera/Follow.cpp"
	"System/Render/Camera/FPS.cpp"
	"System/Render/Camera/Orbit.cpp"
	"System/Render/Math.cpp"
	"System/Render/Mesh.cpp"
	"System/Render/Primitive.cpp"
	"System/Render/Technique/Mesh.cpp"
	"System/Scene.cpp"
	"System/Window.cpp"
	"System/World.cpp"
	"Utility/Base64.cpp"
	"Utility/GLTF2.cpp"
	"Utility/GLTF2/Accessor.cpp"
	"Utility/GLTF2/Animation.cpp"
	"Utility/GLTF2/Asset.cpp"
	"Utility/GLTF2/BufferView.cpp"
	"Utility/GLTF2/Mesh.cpp"
	"Utility/GLTF2/Node.cpp"
	"Utility/Image.cpp")

target_link_libraries(EngineLib glad)
target_link_libraries(EngineLib glfw)

target_link_libraries(ProjectLib INTERFACE EngineLib)
