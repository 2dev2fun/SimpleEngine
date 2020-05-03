// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Shader/Mesh.h"

namespace engine {

MeshShader::MeshShader()
		: mWorldTransform(0xFFFFFFFF)
		, mViewProjection(0xFFFFFFFF) {
	attachVS("source/System/Render/Backend/OpenGL/GLSL/Mesh.vs");
	attachFS("source/System/Render/Backend/OpenGL/GLSL/Mesh.fs");

	compile();
	active();

	mViewProjection = getUniform("uViewProjection");
	mWorldTransform = getUniform("uWorldTransform");
}

MeshShader::~MeshShader() {}

} // namespace engine
