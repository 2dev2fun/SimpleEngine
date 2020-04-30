// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"

#include <rapidjson/document.h>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

struct Node {
	void load(rj::Value& node);

	Bool hasMesh() const;
	auto getMesh() const;

	Int32               mMesh        = -1;
	Int32               mSkin        = -1;
	Vec3                mTranslation;
	Quat                mRotation;
	Mat4                mMatrix;
	std::vector<UInt32> mChildren;
};

inline Bool Node::hasMesh() const {
	return mMesh >= 0;
}

inline auto Node::getMesh() const {
	ASSERT(hasMesh());
	return mMesh;
}

} // namespace gltf2
} // namespace engine
