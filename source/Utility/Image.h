// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Vector3.h"

#include <string>

namespace engine {

class Image {
public:
	Image(std::string const& path);
	Image(Vec3 const& color);
	~Image();

	UInt32 getWidth() const;
	UInt32 getHeight() const;
	UInt32 getChannels() const;

	UInt8* getData() const;
private:
	enum class Type {
		File,
		Vec3,
	};

	Type mType;
	Int32 mWidth;
	Int32 mHeight;
	Int32 mChannels;
	UInt8* mData;
};

inline UInt32 Image::getWidth() const {
	return mWidth;
}

inline UInt32 Image::getHeight() const {
	return mHeight;
}

inline UInt32 Image::getChannels() const {
	return mChannels;
}

inline UInt8* Image::getData() const {
	return mData;
}

} // namespace engine
