// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Render/Backend//OpenGL/Shader.h"

namespace engine {

class MeshShader : public Shader {
public:
	MeshShader();
	~MeshShader();

	void setViewProjection(Mat4 const& value);
	void setWorldTransform(Mat4 const& value);
private:
	GLuint mWorldTransform;
	GLuint mViewProjection;
};

inline void MeshShader::setViewProjection(Mat4 const& value) {
	setMat4(mViewProjection, value);
}

inline void MeshShader::setWorldTransform(Mat4 const& value) {
	setMat4(mWorldTransform, value);
}

} // namespace engine
