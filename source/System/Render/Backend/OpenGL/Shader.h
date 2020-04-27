// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix2x2.h"
#include "Math/Matrix2x2/Function.h"
#include "Math/Matrix3x3.h"
#include "Math/Matrix3x3/Function.h"
#include "Math/Matrix4x4.h"
#include "Math/Matrix4x4/Function.h"
#include "Math/Vector2.h"
#include "Math/Vector2/Function.h"
#include "Math/Vector3.h"
#include "Math/Vector3/Function.h"
#include "Math/Vector4.h"
#include "Math/Vector4/Function.h"

#include <glad/glad.h>

#include <string>

namespace engine {

class Shader {
public:
	void active();
protected:
	Shader();
	~Shader();

	void attachVS(std::string const& path);
	void attachGS(std::string const& path);
	void attachFS(std::string const& path);

	void compile();

	GLuint getUniform(std::string const& name);
	GLuint getAttribute(std::string const& name);

	void setMat2(GLuint location, Mat2 const& value, UInt32 number = 1);
	void setMat3(GLuint location, Mat3 const& value, UInt32 number = 1);
	void setMat4(GLuint location, Mat4 const& value, UInt32 number = 1);

	void setVec2(GLuint location, Vec2 const& value, UInt32 number = 1);
	void setVec3(GLuint location, Vec3 const& value, UInt32 number = 1);
	void setVec4(GLuint location, Vec4 const& value, UInt32 number = 1);
private:
	void compileShader(std::string const& path, GLenum type, GLuint& shader);

	void checkShader(GLuint shader);
	void checkProgram(GLenum type);

	GLuint mProgram;
	GLuint mVShader;
	GLuint mGShader;
	GLuint mFShader;
};

inline void Shader::attachVS(std::string const& path) {
	compileShader(path, GL_VERTEX_SHADER, mVShader);
}

inline void Shader::attachGS(std::string const& path) {
	compileShader(path, GL_GEOMETRY_SHADER, mGShader);
}

inline void Shader::attachFS(std::string const& path) {
	compileShader(path, GL_FRAGMENT_SHADER, mFShader);
}

inline void Shader::setMat2(GLuint location, Mat2 const& value, UInt32 number) {
	glUniformMatrix2fv(location, number, GL_FALSE, math::getPointer(value));
}

inline void Shader::setMat3(GLuint location, Mat3 const& value, UInt32 number) {
	glUniformMatrix3fv(location, number, GL_FALSE, math::getPointer(value));
}

inline void Shader::setMat4(GLuint location, Mat4 const& value, UInt32 number) {
	glUniformMatrix4fv(location, number, GL_FALSE, math::getPointer(value));
}

inline void Shader::setVec2(GLuint location, Vec2 const& value, UInt32 number) {
	glUniform2fv(location, number, math::getPointer(value));
}

inline void Shader::setVec3(GLuint location, Vec3 const& value, UInt32 number) {
	glUniform3fv(location, number, math::getPointer(value));
}

inline void Shader::setVec4(GLuint location, Vec4 const& value, UInt32 number) {
	glUniform4fv(location, number, math::getPointer(value));
}

} // namespace engine
