// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Utility/GLTF2/Accessor.h"

#include <rapidjson/document.h>

namespace engine {
namespace gltf2 {

void Accessor::load(rj::Value& accessor) {
	auto bufferViewIt = accessor.FindMember("bufferView");
	ASSERT(bufferViewIt != accessor.MemberEnd());

	auto& bufferView = bufferViewIt->value;
	ASSERT(bufferView.IsUint());

	mBufferView = bufferView.GetUint();

	auto byteOffsetIt = accessor.FindMember("byteOffset");
	if (byteOffsetIt != accessor.MemberEnd()) {
		auto& byteOffset = byteOffsetIt->value;
		ASSERT(byteOffset.IsUint());
		mByteOffset = byteOffset.GetUint();
	}

	auto componentTypeIt = accessor.FindMember("componentType");
	ASSERT(componentTypeIt != accessor.MemberEnd());

	auto& componentType = componentTypeIt->value;
	ASSERT(componentType.IsUint());

	mComponentType = ComponentType(componentType.GetUint());

	auto countIt = accessor.FindMember("count");
	ASSERT(countIt != accessor.MemberEnd());

	auto& count = countIt->value;
	ASSERT(count.IsUint());

	mCount = count.GetUint();


	auto typeIt = accessor.FindMember("type");
	ASSERT(typeIt != accessor.MemberEnd());

	auto& type = typeIt->value;
	ASSERT(type.IsString());

	std::string const& typeString = type.GetString();

	if (typeString == "SCALAR") { mType = Accessor::Type::SCALAR; } else
	if (typeString == "VEC2")   { mType = Accessor::Type::VEC2;   } else
	if (typeString == "VEC3")   { mType = Accessor::Type::VEC3;   } else
	if (typeString == "VEC4")   { mType = Accessor::Type::VEC4;   } else
	if (typeString == "MAT2")   { mType = Accessor::Type::MAT2;   } else
	if (typeString == "MAT3")   { mType = Accessor::Type::MAT3;   } else
	if (typeString == "MAT4")   { mType = Accessor::Type::MAT4;   }


	auto maxIt = accessor.FindMember("max");
	if (maxIt != accessor.MemberEnd()) {
		auto& max = maxIt->value;
		ASSERT(max.IsArray());

		mMax.resize(max.Size());

		for (rj::SizeType j = 0; j < max.Size(); ++j) {
			ASSERT(max[j].IsNumber());
			mMax[j] = max[j].GetFloat();
		}
	}

	auto minIt = accessor.FindMember("min");
	if (minIt != accessor.MemberEnd()) {
		auto& min = minIt->value;
		ASSERT(min.IsArray());

		mMin.resize(min.Size());

		for (rj::SizeType j = 0; j < min.Size(); ++j) {
			ASSERT(min[j].IsNumber());
			mMin[j] = min[j].GetFloat();
		}
	}

	auto sparseIt = accessor.FindMember("sparse");
	if (sparseIt != accessor.MemberEnd()) {
		auto& sparse = sparseIt->value;
		ASSERT(sparse.IsObject());
		mSparse.load(sparse);
	}
}

void Accessor::Sparse::load(rj::Value& sparse) {
	auto countIt = sparse.FindMember("count");
	if (countIt != sparse.MemberEnd()) {
		auto& count = countIt->value;
		ASSERT(count.IsUint());
		mCount = count.GetUint();
	}

	auto indicesIt = sparse.FindMember("indices");
	if (indicesIt != sparse.MemberEnd()) {
		auto& indices = indicesIt->value;
		ASSERT(indices.IsObject());
		mIndices.load(indices);
	}

	auto valuesIt = sparse.FindMember("values");
	if (valuesIt != sparse.MemberEnd()) {
		auto& values = valuesIt->value;
		ASSERT(values.IsObject());
		mValues.load(values);
	}
}

void Accessor::Sparse::Indices::load(rj::Value& indices) {
	auto bufferViewIt = indices.FindMember("bufferView");
	if (bufferViewIt != indices.MemberEnd()) {
		auto& bufferView = bufferViewIt->value;
		ASSERT(bufferView.IsUint());
		mBufferView = bufferView.GetUint();
	}

	auto byteOffsetIt = indices.FindMember("byteOffset");
	if (byteOffsetIt != indices.MemberEnd()) {
		auto& byteOffset = byteOffsetIt->value;
		ASSERT(byteOffset.IsUint());
		mByteOffset = byteOffset.GetUint();
	}

	auto componentTypeIt = indices.FindMember("componentType");
	if (componentTypeIt != indices.MemberEnd()) {
		auto& componentType = componentTypeIt->value;
		ASSERT(componentType.IsUint());
		mComponentType = ComponentType(componentType.GetUint());
	}
}

void Accessor::Sparse::Values::load(rj::Value& values) {
	auto bufferViewIt = values.FindMember("bufferView");
	if (bufferViewIt != values.MemberEnd()) {
		auto& bufferView = bufferViewIt->value;
		ASSERT(bufferView.IsUint());
		mBufferView = bufferView.GetUint();
	}

	auto byteOffsetIt = values.FindMember("byteOffset");
	if (byteOffsetIt != values.MemberEnd()) {
		auto& byteOffset = byteOffsetIt->value;
		ASSERT(byteOffset.IsUint());
		mByteOffset = byteOffset.GetUint();
	}
}

} // namespace gltf2
} // namespace engine
