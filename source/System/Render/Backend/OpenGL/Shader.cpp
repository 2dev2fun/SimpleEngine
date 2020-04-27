// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Shader.h"

#include <fstream>
#include <istream>
#include <sstream>
#include <string>

using namespace engine;

Shader::Shader()
		: mProgram(0xFFFFFFFF)
		, mVShader(0xFFFFFFFF)
		, mGShader(0xFFFFFFFF)
		, mFShader(0xFFFFFFFF) {}

Shader::~Shader() {
	if (mVShader != 0xFFFFFFFF) { glDeleteShader(mVShader);  }
	if (mGShader != 0xFFFFFFFF) { glDeleteShader(mGShader);  }
	if (mFShader != 0xFFFFFFFF) { glDeleteShader(mFShader);  }
	if (mProgram != 0xFFFFFFFF) { glDeleteProgram(mProgram); }
}

void Shader::active() {
	if (mProgram != 0xFFFFFFFF) {
		glUseProgram(mProgram);
	} else {
		LOG_CRITICAL("Shader program doesn't work!");
	}
}

void Shader::compile() {
	mProgram = glCreateProgram();

	if (mVShader != 0xFFFFFFFF) { glAttachShader(mProgram, mVShader); }
	if (mGShader != 0xFFFFFFFF) { glAttachShader(mProgram, mGShader); }
	if (mFShader != 0xFFFFFFFF) { glAttachShader(mProgram, mFShader); }

	glLinkProgram(mProgram);

	checkProgram(GL_LINK_STATUS);
	checkProgram(GL_VALIDATE_STATUS);

	if (mVShader != 0xFFFFFFFF) { glDeleteShader(mVShader); mVShader = 0xFFFFFFFF; }
	if (mGShader != 0xFFFFFFFF) { glDeleteShader(mGShader); mGShader = 0xFFFFFFFF; }
	if (mFShader != 0xFFFFFFFF) { glDeleteShader(mFShader); mFShader = 0xFFFFFFFF; }
}

void Shader::compileShader(std::string const& path, GLenum type, GLuint& shader) {

	std::ifstream file(path);

	if (!file.is_open()) { LOG_CRITICAL("Error reading shader file: {}", path); }

	std::stringstream stream;
	stream << file.rdbuf();

	std::string code = stream.str();
	GLchar const* data = code.c_str();

	shader = glCreateShader(type);
	glShaderSource(shader, 1, &data, nullptr);
	glCompileShader(shader);

	checkShader(shader);
}

void Shader::checkShader(GLuint shader) {
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == GL_TRUE) { return; }

	UInt32 logSize = 1024;
	GLchar infoLog[logSize];
	glGetShaderInfoLog(shader, logSize, nullptr, infoLog);

	LOG_CRITICAL("Shader compiler error: {}", static_cast<Char*>(infoLog));
}

void Shader::checkProgram(GLenum type) {
	GLint status;
	glGetProgramiv(mProgram, type, &status);

	if (status == GL_TRUE) { return; }

	UInt32 logSize = 1024;
	GLchar infoLog[logSize];
	glGetProgramInfoLog(mProgram, logSize, nullptr, infoLog);

	LOG_CRITICAL("Shader program error: {}", static_cast<Char*>(infoLog));
}

GLuint Shader::getUniform(std::string const& name) {
	GLuint location = glGetUniformLocation(mProgram, name.c_str());
	if (location == 0xFFFFFFFF) { LOG_CRITICAL("Not found uniform location: {}", name); }
	return location;
}

GLuint Shader::getAttribute(std::string const& name) {
	GLuint location = glGetAttribLocation(mProgram, name.c_str());
	if (location == 0xFFFFFFFF) { LOG_CRITICAL("Not found attribute location: {}", name); }
	return location;
}
