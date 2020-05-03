// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <rapidjson/document.h>

#include <string>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

class BufferView {
public:
	enum class Target {
		NONE                 = 0,
		ARRAY_BUFFER         = 34962,
		ELEMENT_ARRAY_BUFFER = 34963,
	};

	void load(rj::Value& bufferView);

	Bool hasBuffer() const;
	auto getBuffer() const;

	auto getByteOffset() const;

	Bool hasByteLength() const;
	auto getByteLength() const;

	Bool hasByteStride() const;
	auto getByteStride() const;

	Bool hasTarget() const;
	auto getTarget() const;

	bool hasName() const;
	auto const& getName() const;
private:
	Int32       mBuffer     = -1;
	UInt32      mByteOffset =  0;
	Int32       mByteLength = -1;
	Int32       mByteStride = -1;
	Target      mTarget     = Target::NONE;
	std::string mName;
};

inline Bool BufferView::hasBuffer() const {
	return mBuffer >= 0;
}

inline auto BufferView::getBuffer() const {
	ASSERT(hasBuffer());
	return mBuffer;
}

inline auto BufferView::getByteOffset() const {
	return mByteOffset;
}

inline Bool BufferView::hasByteLength() const {
	return mByteLength >= 0;
}

inline auto BufferView::getByteLength() const {
	ASSERT(hasByteLength());
	return mByteLength;
}

inline Bool BufferView::hasByteStride() const {
	return mByteStride >= 0;
}

inline auto BufferView::getByteStride() const {
	ASSERT(hasByteStride());
	return mByteStride;
}

inline Bool BufferView::hasTarget() const {
	return mTarget != Target::NONE;
}

inline auto BufferView::getTarget() const {
	ASSERT(hasTarget());
	return mTarget;
}

inline bool BufferView::hasName() const {
	return mName.size() > 0;
}

inline auto const& BufferView::getName() const {
	ASSERT(hasName());
	return mName;
}

} // namespace gltf2
} // namespace engine
