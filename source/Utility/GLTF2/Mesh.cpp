// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/Mesh.h"

namespace engine {
namespace gltf2 {

void Mesh::load(rj::Value& mesh) {
	auto primitivesIt = mesh.FindMember("primitives");
	ASSERT(primitivesIt != mesh.MemberEnd());

	auto& primitives = primitivesIt->value;
	ASSERT(primitives.IsArray());

	mPrimitives.resize(primitives.Size());

	for (rj::SizeType primitive = 0; primitive < primitives.Size(); ++primitive) {
		auto attributesIt = primitives[primitive].FindMember("attributes");
		ASSERT(attributesIt != primitives[primitive].MemberEnd());

		auto& attributes = attributesIt->value;
		ASSERT(attributes.IsObject());

		auto positionIt = attributes.FindMember("POSITION");
		if (positionIt != attributes.MemberEnd()) {
			auto& position = positionIt->value;
			ASSERT(position.IsUint());
			mPrimitives[primitive].mAttribute.POSITION = position.GetUint();
		}

		auto normalIt = attributes.FindMember("NORMAL");
		if (normalIt != attributes.MemberEnd()) {
			auto& normal = normalIt->value;
			ASSERT(normal.IsUint());
			mPrimitives[primitive].mAttribute.NORMAL = normal.GetUint();
		}

		auto tangentIt = attributes.FindMember("TANGENT");
		if (tangentIt != attributes.MemberEnd()) {
			auto& tangent = tangentIt->value;
			ASSERT(tangent.IsUint());
			mPrimitives[primitive].mAttribute.TANGENT = tangent.GetUint();
		}

		auto texCoord0It = attributes.FindMember("TEXCOORD_0");
		if (texCoord0It != attributes.MemberEnd()) {
			auto& texCoord0 = texCoord0It->value;
			ASSERT(texCoord0.IsUint());
			mPrimitives[primitive].mAttribute.TEXCOORD_0 = texCoord0.GetUint();
		}

		auto texCoord1It = attributes.FindMember("TEXCOORD_1");
		if (texCoord1It != attributes.MemberEnd()) {
			auto& texCoord1 = texCoord1It->value;
			ASSERT(texCoord1.IsUint());
			mPrimitives[primitive].mAttribute.TEXCOORD_1 = texCoord1.GetUint();
		}

		auto color0It = attributes.FindMember("COLOR_0");
		if (color0It != attributes.MemberEnd()) {
			auto& color0 = color0It->value;
			ASSERT(color0.IsUint());
			mPrimitives[primitive].mAttribute.COLOR_0 = color0.GetUint();
		}

		auto joints0It = attributes.FindMember("JOINTS_0");
		if (joints0It != attributes.MemberEnd()) {
			auto& joints0 = joints0It->value;
			ASSERT(joints0.IsUint());
			mPrimitives[primitive].mAttribute.JOINTS_0 = joints0.GetUint();
		}

		auto weights0It = attributes.FindMember("WEIGHTS_0");
		if (weights0It != attributes.MemberEnd()) {
			auto& weights0 = weights0It->value;
			ASSERT(weights0.IsUint());
			mPrimitives[primitive].mAttribute.WEIGHTS_0 = weights0.GetUint();
		}

		auto indicesIt = primitives[primitive].FindMember("indices");
		if (indicesIt != primitives[primitive].MemberEnd()) {
			auto& indices = indicesIt->value;
			ASSERT(indices.IsUint());
			mPrimitives[primitive].mIndices = indices.GetUint();
		}
	}
}

} // namespace gltf2
} // namespace engine
