// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <rapidjson/document.h>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

class Mesh {
public:
	struct Primitive {
		enum class Mode {
			POINTS,
			LINES,
			LINE_LOOP,
			LINE_STRIP,
			TRIANGLES,
			TRIANGLE_STRIP,
			TRIANGLE_FAN,
		};

		struct Attribute {
			Int32 POSITION   = -1;
			Int32 NORMAL     = -1;
			Int32 TANGENT    = -1;
			Int32 TEXCOORD_0 = -1;
			Int32 TEXCOORD_1 = -1;
			Int32 COLOR_0    = -1;
			Int32 JOINTS_0   = -1;
			Int32 WEIGHTS_0  = -1;
		};

		Attribute mAttribute;
		Int32     mIndices   = -1;
		Mode      mMode      = Mode::TRIANGLES;
	};

	void load(rj::Value& mesh);

	Bool hasIndices(UInt32 primitive) const;
	auto getIndices(UInt32 primitive) const;

	Bool hasPosition(UInt32 primitive) const;
	auto getPosition(UInt32 primitive) const;

	Bool hasNormal(UInt32 primitive) const;
	auto getNormal(UInt32 primitive) const;

	Bool hasTangent(UInt32 primitive) const;
	auto getTangent(UInt32 primitive) const;

	Bool hasTexCoord0(UInt32 primitive) const;
	auto getTexCoord0(UInt32 primitive) const;

	Bool hasTexCoord1(UInt32 primitive) const;
	auto getTexCoord1(UInt32 primitive) const;

	Bool hasColor0(UInt32 primitive) const;
	auto getColor0(UInt32 primitive) const;

	Bool hasJoints0(UInt32 primitive) const;
	auto getJoints0(UInt32 primitive) const;

	Bool hasWeights0(UInt32 primitive) const;
	auto getWeights0(UInt32 primitive) const;

	auto getPrimitivesSize() const;
private:
	std::vector<Primitive> mPrimitives;
};

inline Bool Mesh::hasIndices(UInt32 primitive) const {
	return mPrimitives[primitive].mIndices >= 0;
}

inline auto Mesh::getIndices(UInt32 primitive) const {
	ASSERT(hasIndices(primitive));
	return mPrimitives[primitive].mIndices;
}

inline Bool Mesh::hasPosition(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.POSITION >= 0;
}

inline auto Mesh::getPosition(UInt32 primitive) const {
	ASSERT(hasPosition(primitive));
	return mPrimitives[primitive].mAttribute.POSITION;
}

inline Bool Mesh::hasNormal(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.NORMAL >= 0;
}

inline auto Mesh::getNormal(UInt32 primitive) const {
	ASSERT(hasNormal(primitive));
	return mPrimitives[primitive].mAttribute.NORMAL;
}

inline Bool Mesh::hasTangent(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.TANGENT >= 0;
}

inline auto Mesh::getTangent(UInt32 primitive) const {
	ASSERT(hasTangent(primitive));
	return mPrimitives[primitive].mAttribute.TANGENT;
}

inline Bool Mesh::hasTexCoord0(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.TEXCOORD_0 >= 0;
}

inline auto Mesh::getTexCoord0(UInt32 primitive) const {
	ASSERT(hasTexCoord0(primitive));
	return mPrimitives[primitive].mAttribute.TEXCOORD_0;
}

inline Bool Mesh::hasTexCoord1(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.TEXCOORD_1 >= 0;
}

inline auto Mesh::getTexCoord1(UInt32 primitive) const {
	ASSERT(hasTexCoord1(primitive));
	return mPrimitives[primitive].mAttribute.TEXCOORD_1;
}

inline Bool Mesh::hasColor0(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.COLOR_0 >= 0;
}

inline auto Mesh::getColor0(UInt32 primitive) const {
	ASSERT(hasColor0(primitive));
	return mPrimitives[primitive].mAttribute.COLOR_0;
}

inline Bool Mesh::hasJoints0(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.JOINTS_0 >= 0;
}

inline auto Mesh::getJoints0(UInt32 primitive) const {
	ASSERT(hasJoints0(primitive));
	return mPrimitives[primitive].mAttribute.JOINTS_0;
}

inline Bool Mesh::hasWeights0(UInt32 primitive) const {
	return mPrimitives[primitive].mAttribute.WEIGHTS_0 >= 0;
}

inline auto Mesh::getWeights0(UInt32 primitive) const {
	ASSERT(hasWeights0(primitive));
	return mPrimitives[primitive].mAttribute.WEIGHTS_0;
}

inline auto Mesh::getPrimitivesSize() const {
	return mPrimitives.size();
}

} // namespace gltf2
} // namespace engine
