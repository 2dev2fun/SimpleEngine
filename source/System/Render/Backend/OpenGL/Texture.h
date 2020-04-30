// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <glad/glad.h>

#include <string>

namespace engine {

class Texture {
public:
	Texture(std::string const& path);
	Texture(Vec3 const& color);
	~Texture();

	void bind(UInt32 index = 0);
private:
	void construct(Image const& image);

	GLuint mTexture;
};

inline void Texture::bind(UInt32 index) {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, mTexture);
}

} // namespace engine
