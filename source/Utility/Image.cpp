// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <string>

using namespace engine;

Image::Image(std::string const& path)
		: mType(Type::File)
		, mWidth(-1)
		, mHeight(-1)
		, mChannels(-1)
		, mData(nullptr) {
	mData = stbi_load(path.c_str(), &mWidth, &mHeight, &mChannels, 0);
}

Image::Image(Vec3 const& color)
		: mType(Type::Vec3)
		, mWidth(1)
		, mHeight(1)
		, mChannels(3)
		, mData(nullptr) {
	mData = new UInt8[3] {
		static_cast<UInt8>(255 * color.x),
		static_cast<UInt8>(255 * color.y),
		static_cast<UInt8>(255 * color.z) };
}

Image::~Image() {
	if (mData == nullptr) { LOG_CRITICAL("mData == nullptr"); }

	switch (mType) {
		case Type::File:
			stbi_image_free(mData);
			break;
		case Type::Vec3:
			delete[] mData;
			break;
		default:
			LOG_CRITICAL("Type undefined!");
	}
}
