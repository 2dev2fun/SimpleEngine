// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Texture.h"
#include "Utility/Image.h"

#include <string>

namespace engine {

Texture::Texture(std::string const& path) : mTexture(0xFFFFFFFF) {
	construct(Image(path));
}

Texture::Texture(Vec3 const& color) : mTexture(0xFFFFFFFF) {
	construct(Image(color));
}

Texture::~Texture() {
	if (mTexture != 0xFFFFFFFF) { glDeleteTextures(1, &mTexture); }
}

void Texture::construct(Image const& image) {
	GLenum format;
	switch (image.getChannels()) {
		case 1 : format = GL_RED;  break;
		case 3 : format = GL_RGB;  break;
		case 4 : format = GL_RGBA; break;
		default: LOG_CRITICAL("Texture format undefined!");
	}
	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glTexImage2D(
			GL_TEXTURE_2D,
			0,
			format,
			image.getWidth(),
			image.getHeight(),
			0,
			format,
			GL_UNSIGNED_BYTE,
			image.getData());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

} // namespace engine
