// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/BufferView.h"

namespace engine {
namespace gltf2 {

void BufferView::load(rj::Value& bufferView) {
	auto bufferIt = bufferView.FindMember("buffer");
	ASSERT(bufferIt != bufferView.MemberEnd());
	auto& buffer = bufferIt->value;
	ASSERT(buffer.IsUint());
	mBuffer = buffer.GetUint();

	auto byteOffsetIt = bufferView.FindMember("byteOffset");
	if (byteOffsetIt != bufferView.MemberEnd()) {
		auto& byteOffset = byteOffsetIt->value;
		ASSERT(byteOffset.IsUint());
		mByteOffset = byteOffset.GetUint();
	}

	auto byteLengthIt = bufferView.FindMember("byteLength");
	ASSERT(byteLengthIt != bufferView.MemberEnd());
	auto& byteLength = byteLengthIt->value;
	ASSERT(byteLength.IsUint());
	mByteLength = byteLength.GetUint();


	auto byteStrideIt = bufferView.FindMember("byteStride");
	if (byteStrideIt != bufferView.MemberEnd()) {
		auto& byteStride = byteStrideIt->value;
		ASSERT(byteStride.IsUint());
		mByteStride = byteStride.GetUint();
	}

	auto targetIt = bufferView.FindMember("target");
	if (targetIt != bufferView.MemberEnd()) {
		auto& target = targetIt->value;
		ASSERT(target.IsUint());
		mTarget = Target(target.GetUint());
	}
}

} // namespace gltf2
} // namespace engine
