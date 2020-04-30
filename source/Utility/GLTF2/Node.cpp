// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/Node.h"

namespace engine {
namespace gltf2 {

void Node::load(rj::Value& node) {
	auto meshIt = node.FindMember("mesh");
	if (meshIt != node.MemberEnd()) {
		auto& mesh = meshIt->value;
		ASSERT(mesh.IsUint());
		mMesh = mesh.GetUint();
	}

	auto skinIt = node.FindMember("skin");
	if (skinIt != node.MemberEnd()) {
		auto& skin = skinIt->value;
		ASSERT(skin.IsUint());
		mSkin = skin.GetUint();
	}

	auto childrenIt = node.FindMember("children");
	if (childrenIt != node.MemberEnd()) {
		auto& children = childrenIt->value;
		ASSERT(children.IsArray());

		mChildren.resize(children.Size());

		for (rj::SizeType i = 0; i < children.Size(); ++i) {
			ASSERT(children[i].IsUint());
			mChildren[i] = children[i].GetUint();
		}
	}

	auto matrixIt = node.FindMember("matrix");
	if (matrixIt != node.MemberEnd()) {
		auto& matrix = matrixIt->value;
		ASSERT(matrix.IsArray());

		for (rj::SizeType i = 0; i < matrix.Size(); ++i) {
			ASSERT(matrix[i].IsFloat());
			mMatrix[i % 4][i / 4] = matrix[i].GetFloat();
		}
	}

	auto translationIt = node.FindMember("translation");
	if (translationIt != node.MemberEnd()) {
		auto& translation = translationIt->value;
		ASSERT(translation.IsArray());
		ASSERT(translation.Size() == 3);

		for (rj::SizeType i = 0; i < translation.Size(); ++i) {
			ASSERT(translation[i].IsFloat() || translation[i].IsInt());
			mTranslation[i] = translation[i].GetFloat();
		}
	}


	auto rotationIt = node.FindMember("rotation");
	if (rotationIt != node.MemberEnd()) {
		auto& rotation = rotationIt->value;
		ASSERT(rotation.IsArray());
		ASSERT(rotation.Size() == 4);

		for (rj::SizeType i = 0; i < rotation.Size(); ++i) {
			ASSERT(rotation[i].IsFloat() || rotation[i].IsInt());
			mRotation[i] = rotation[i].GetFloat();
		}
	}
}

} // namespace gltf2
} // namespace engine
