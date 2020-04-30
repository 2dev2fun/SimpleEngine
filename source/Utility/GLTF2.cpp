// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Base64.h"
#include "Game.h"
#include "System/Render/Backend/OpenGL/Texture.h"
#include "System/Render/Backend/OpenGL/VertexArray.h"
#include "System/Render/Mesh.h"
#include "System/Render/Primitive.h"
#include "Utility/GLTF2.h"

#include <rapidjson/document.h>

#include <algorithm>
#include <fstream>
#include <memory>
#include <sstream>
#include <streambuf>
#include <vector>

namespace rj = rapidjson;

namespace engine {

GLTF2::GLTF2(const std::string& path) : mPath(path) {
	std::ifstream file(mPath);
	std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	mDoc.Parse(json.c_str());

	rj::StringBuffer buffer;
	rj::Writer<rj::StringBuffer> writer(buffer);
	mDoc.Accept(writer);

	loadAccessors();
	loadScenes();
	loadNodes();
	loadMeshes();
	loadBuffers();
	loadBufferViews();
	loadSamplers();
	loadImages();
	loadTextures();
	loadAnimations();
	loadAsset();
	loadSkins();
}

GLTF2::~GLTF2() {}

void GLTF2::fillMesh(Mesh* meshResource) {
	enum {
		POSITION   = 1 << 0,
		NORMAL     = 1 << 1,
		TANGENT    = 1 << 2,
		TEXCOORD_0 = 1 << 3,
		TEXCOORD_1 = 1 << 4,
		COLOR_0    = 1 << 5,
		JOINTS_0   = 1 << 6,
		WEIGHTS_0  = 1 << 7,
		INDICES16  = 1 << 8,
		INDICES32  = 1 << 9,
	};

	for (UInt32 node = 0; node < mNodes.size(); ++node) {
		if (mNodes[node].hasMesh()) {
			UInt32 mesh = mNodes[node].getMesh();
			UInt32 mask = 0;
			std::vector<Primitive> primitives(mMeshes[mesh].getPrimitivesSize());
			for (UInt32 primitive = 0; primitive < mMeshes[mesh].getPrimitivesSize(); ++primitive) {
				if (mMeshes[mesh].hasPosition(primitive))  { mask |= POSITION;   }
				if (mMeshes[mesh].hasNormal(primitive))    { mask |= NORMAL;     }
				if (mMeshes[mesh].hasTangent(primitive))   { mask |= TANGENT;    }
				if (mMeshes[mesh].hasTexCoord0(primitive)) { mask |= TEXCOORD_0; }
				if (mMeshes[mesh].hasTexCoord1(primitive)) { mask |= TEXCOORD_1; }
				if (mMeshes[mesh].hasColor0(primitive))    { mask |= COLOR_0;    }
				if (mMeshes[mesh].hasJoints0(primitive))   { mask |= JOINTS_0;   }
				if (mMeshes[mesh].hasWeights0(primitive))  { mask |= WEIGHTS_0;  }

				if (mMeshes[mesh].hasIndices(primitive)) {
					auto accessor = mMeshes[mesh].getIndices(primitive);
					switch (mAccessors[accessor].getComponentType()) {
						case gltf2::Accessor::ComponentType::USHORT:
							mask |= INDICES16;
							break;
						case gltf2::Accessor::ComponentType::UINT:
							mask |= INDICES32;
							break;
						default:
							ASSERT(0);
					}
				}

				switch (mask) {
					case POSITION:
						primitives[primitive].setVertexArray(std::make_shared<VertexArray>(
								getPositions(mesh, primitive)));
						break;

					case POSITION | INDICES16:
						primitives[primitive].setVertexArray(std::make_shared<VertexArray>(
								getPositions(mesh, primitive),
								getIndices16(mesh, primitive)));
						break;

					case POSITION | INDICES32:
						primitives[primitive].setVertexArray(std::make_shared<VertexArray>(
								getPositions(mesh, primitive),
								getIndices32(mesh, primitive)));
						break;

					default:
						ASSERT(0);
				}
			}
			meshResource->setPrimivites(primitives);
			return;
		}
	}
}

UInt32 GLTF2::getComponentTypeElements(const std::string& type) {
	if (type == "SCALAR") { return 1;  }
	if (type == "VEC2")   { return 2;  }
	if (type == "VEC3")   { return 3;  }
	if (type == "VEC4")   { return 4;  }
	if (type == "MAT2")   { return 4;  }
	if (type == "MAT3")   { return 9;  }
	if (type == "MAT4")   { return 16; }

	ASSERT(0);
	return 0;
}

UInt32 GLTF2::getComponentTypeBytes(UInt32 type) {
	if (type == 5120) { return 1; }
	if (type == 5120) { return 1; }
	if (type == 5121) { return 1; }
	if (type == 5122) { return 2; }
	if (type == 5123) { return 2; }
	if (type == 5125) { return 4; }
	if (type == 5126) { return 4; }

	ASSERT(0);
	return 0;
}

std::vector<UInt16> GLTF2::getIndices16(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getIndices(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::SCALAR);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::USHORT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	Int32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;

	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<UInt16> indices(count);

	ASSERT(mBuffers[buffer].data.size() >= byteOffset + count);

	for (UInt32 i = 0; i < count; ++i) {
		indices[i] = *reinterpret_cast<UInt16*>(data + sizeof(UInt16) * i);
	}

	return indices;
}

std::vector<UInt32> GLTF2::getIndices32(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getIndices(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::SCALAR);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::UINT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	Int32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<UInt32> indices(count);

	for (UInt32 i = 0; i < count; ++i) {
		indices[i] = *reinterpret_cast<UInt32*>(data + sizeof(UInt32) * i);
	}

	return indices;
}

std::vector<UInt16> GLTF2::getJoints16(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getJoints0(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC4);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::USHORT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	UInt32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<UInt16> joints(4 * count);

	ASSERT(mBufferViews[bufferView].byteStride != -1);
	UInt32 byteStride = mBufferViews[bufferView].byteStride;

	for (UInt32 i = 0; i < count; ++i) {
		UInt16* start = reinterpret_cast<UInt16*>(data + byteStride * i);

		joints[4 * i + 0] = *(start + 0);
		joints[4 * i + 1] = *(start + 1);
		joints[4 * i + 2] = *(start + 2);
		joints[4 * i + 3] = *(start + 3);
	}

	return joints;
}

std::vector<UInt32> GLTF2::getJoints32(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getJoints0(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC4);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::UINT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	UInt32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<UInt32> joints(4 * count);

	const UInt32 stride = 4 * sizeof(UInt32);

	for (UInt32 i = 0; i < count; ++i) {
		joints[4 * i + 0] = *reinterpret_cast<UInt32*>(data + stride * i + 0 * sizeof(UInt32));
		joints[4 * i + 1] = *reinterpret_cast<UInt32*>(data + stride * i + 1 * sizeof(UInt32));
		joints[4 * i + 2] = *reinterpret_cast<UInt32*>(data + stride * i + 2 * sizeof(UInt32));
		joints[4 * i + 3] = *reinterpret_cast<UInt32*>(data + stride * i + 3 * sizeof(UInt32));
	}

	return joints;
}

std::vector<Float32> GLTF2::getWeights(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getWeights0(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC4);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::FLOAT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	UInt32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<Float32> weights(4 * count);

	const UInt32 stride = 4 * sizeof(Float32);

	for (UInt32 i = 0; i < count; ++i) {
		weights[4 * i + 0] = *reinterpret_cast<Float32*>(data + stride * i + 0 * sizeof(Float32));
		weights[4 * i + 1] = *reinterpret_cast<Float32*>(data + stride * i + 1 * sizeof(Float32));
		weights[4 * i + 2] = *reinterpret_cast<Float32*>(data + stride * i + 2 * sizeof(Float32));
		weights[4 * i + 3] = *reinterpret_cast<Float32*>(data + stride * i + 3 * sizeof(Float32));
	}

	return weights;
}

std::vector<Float32> GLTF2::getTexCoord0(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getTexCoord0(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC2);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::FLOAT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	UInt32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<Float32> texCoords(2 * count);

	const UInt32 stride = 2 * sizeof(Float32);

	for (UInt32 i = 0; i < count; ++i) {
		texCoords[2 * i + 0] = *reinterpret_cast<Float32*>(data + stride * i + 0 * sizeof(Float32));
		texCoords[2 * i + 1] = *reinterpret_cast<Float32*>(data + stride * i + 1 * sizeof(Float32));
	}

	return texCoords;
}

std::vector<Float32> GLTF2::getTexCoord1(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getTexCoord1(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC2);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::FLOAT);

	UInt32 bufferView = mAccessors[accessor].getBufferView();
	UInt32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	UInt32 buffer = mBufferViews[bufferView].buffer;

	UInt32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<Float32> texCoords(2 * count);

	const UInt32 stride = 2 * sizeof(Float32);

	for (UInt32 i = 0; i < count; ++i) {
		texCoords[2 * i + 0] = *reinterpret_cast<Float32*>(data + stride * i + 0 * sizeof(Float32));
		texCoords[2 * i + 1] = *reinterpret_cast<Float32*>(data + stride * i + 1 * sizeof(Float32));
	}

	return texCoords;
}

std::vector<Float32> GLTF2::getPositions(UInt32 mesh, UInt32 primitive) {
	UInt32 accessor = mMeshes[mesh].getPosition(primitive);

	mAccessors[accessor].hasType(gltf2::Accessor::Type::VEC3);
	mAccessors[accessor].hasComponentType(gltf2::Accessor::ComponentType::FLOAT);

	Int32 bufferView = mAccessors[accessor].getBufferView();
	Int32 count = mAccessors[accessor].getCount();

	ASSERT(mBufferViews[bufferView].buffer >= 0);
	Int32 buffer = mBufferViews[bufferView].buffer;

	Int32 byteOffset = mAccessors[accessor].getByteOffset() + mBufferViews[bufferView].byteOffset;
	UInt8* data = mBuffers[buffer].data.data() + byteOffset;

	std::vector<Float32> positions(3 * count);

	const UInt32 stride = 3 * sizeof(Float32);

	for (Int32 i = 0; i < count; ++i) {
		positions[3 * i + 0] = *reinterpret_cast<Float32*>(data + stride * i + 0 * sizeof(Float32));
		positions[3 * i + 1] = *reinterpret_cast<Float32*>(data + stride * i + 1 * sizeof(Float32));
		positions[3 * i + 2] = *reinterpret_cast<Float32*>(data + stride * i + 2 * sizeof(Float32));
	}

	if (mAccessors[accessor].getSparse().hasCount()) {
		auto const& sparse = mAccessors[accessor].getSparse();

		UInt32 indicesBufferView = sparse.getIndices().getBufferView();
		UInt32 valuesBufferView  = sparse.getValues().getBufferView();

		ASSERT(mBufferViews[indicesBufferView].buffer >= 0);
		UInt32 indicesBuffer = mBufferViews[indicesBufferView].buffer;

		ASSERT(mBufferViews[valuesBufferView].buffer >= 0);
		UInt32 valuesBuffer  = mBufferViews[valuesBufferView].buffer;

		UInt32 indicesByteOffset = 0;

		ASSERT(mBufferViews[indicesBufferView].byteOffset >= 0);
		indicesByteOffset += mBufferViews[indicesBufferView].byteOffset;

		indicesByteOffset += sparse.getIndices().getByteOffset();

		UInt32 valuesByteOffset = 0;

		ASSERT(mBufferViews[valuesBufferView].byteOffset >= 0);
		valuesByteOffset += mBufferViews[valuesBufferView].byteOffset;

		valuesByteOffset += sparse.getValues().getByteOffset();

		ASSERT(mBuffers[indicesBuffer].data.size() > 0);
		UInt8* indices = mBuffers[indicesBuffer].data.data() + indicesByteOffset;

		ASSERT(mBuffers[valuesBuffer].data.size() > 0);
		UInt8* values = mBuffers[valuesBuffer].data.data() + valuesByteOffset;

		UInt32 count = sparse.getCount();

		for (UInt32 i = 0; i < count; ++i) {
			UInt16 index = *(reinterpret_cast<UInt16*>(indices) + i);
			for (UInt32 j = 0; j < 3; ++j) {
				Float32 value = *(reinterpret_cast<Float32*>(values) + 3 * i + j);
				*(reinterpret_cast<Float32*>(positions.data()) + 3 * index + j) = value;
			}
		}
	}

	return positions;
}

void GLTF2::loadScenes() {
	auto scenesIt = mDoc.FindMember("scenes");
	ASSERT(scenesIt != mDoc.MemberEnd());

	auto& scenes = scenesIt->value;
	ASSERT(scenes.IsArray());

	mScenes.resize(scenes.Size());

	for (rj::SizeType i = 0; i < scenes.Size(); ++i) {
		auto nodesIt = scenes[i].FindMember("nodes");
		ASSERT(nodesIt != scenes[i].MemberEnd());

		auto& nodes = nodesIt->value;
		ASSERT(nodes.IsArray());

		mScenes[i].nodes.resize(nodes.Size());

		for (rj::SizeType j = 0; j < nodes.Size(); ++j) {
			ASSERT(nodes[j].IsUint());
			mScenes[i].nodes[j] = nodes[j].GetUint();
		}
	}
}

void GLTF2::loadSkins() {
	auto skinsIt = mDoc.FindMember("skins");
	if (skinsIt == mDoc.MemberEnd()) { return; }

	auto& skins = skinsIt->value;
	ASSERT(skins.IsArray());

	mSkins.resize(skins.Size());

	for (rj::SizeType skin = 0; skin < skins.Size(); ++skin) {
		auto inverseBindMatricesIt = skins[skin].FindMember("inverseBindMatrices");
		if (inverseBindMatricesIt != skins[skin].MemberEnd()) {
			auto& inverseBindMatrices = inverseBindMatricesIt->value;
			ASSERT(inverseBindMatrices.IsUint());

			mSkins[skin].inverseBindMatrices = inverseBindMatrices.GetUint();
		}

		auto jointsIt = skins[skin].FindMember("joints");
		if (jointsIt != skins[skin].MemberEnd()) {
			auto& joints = jointsIt->value;
			ASSERT(joints.IsArray());

			mSkins[skin].joints.resize(joints.Size());

			for (rj::SizeType joint = 0; joint < joints.Size(); ++joint) {
				ASSERT(joints[joint].IsUint());
				mSkins[skin].joints[joint] = joints[joint].GetUint();
			}
		}
	}
}

void GLTF2::loadNodes() {
	auto nodesIt = mDoc.FindMember("nodes");
	ASSERT(nodesIt != mDoc.MemberEnd());

	auto& nodes = nodesIt->value;
	ASSERT(nodes.IsArray());

	mNodes.resize(nodes.Size());

	for (rj::SizeType node = 0; node < nodes.Size(); ++node) {
		mNodes[node].load(nodes[node]);
	}
}

void GLTF2::loadMeshes() {
	auto meshesIt = mDoc.FindMember("meshes");
	ASSERT(meshesIt != mDoc.MemberEnd());

	auto& meshes = meshesIt->value;
	ASSERT(meshes.IsArray());

	mMeshes.resize(meshes.Size());

	for (rj::SizeType mesh = 0; mesh < meshes.Size(); ++mesh) {
		mMeshes[mesh].load(meshes[mesh]);
	}
}

void GLTF2::loadBuffers() {
	auto buffersIt = mDoc.FindMember("buffers");
	ASSERT(buffersIt != mDoc.MemberEnd());

	auto& buffers = buffersIt->value;
	ASSERT(buffers.IsArray());

	mBuffers.resize(buffers.Size());

	for (rj::SizeType i = 0; i < buffers.Size(); ++i) {
		auto uriIt = buffers[i].FindMember("uri");
		ASSERT(uriIt != buffers[i].MemberEnd());

		auto& uri = uriIt->value;
		ASSERT(uri.IsString());

		mBuffers[i].uri = uri.GetString();


		auto byteLengthIt = buffers[i].FindMember("byteLength");
		ASSERT(byteLengthIt != buffers[i].MemberEnd());

		auto& byteLength = byteLengthIt->value;
		ASSERT(byteLength.IsUint());

		mBuffers[i].byteLength = byteLength.GetUint();
		mBuffers[i].data.resize(mBuffers[i].byteLength);

		if (mBuffers[i].uri.substr(mBuffers[i].uri.find('.') + 1, 3) == "bin") {
			loadBuffersBinData(i);
		} else {
			loadBuffersUriData(i);
		}
	}
}

void GLTF2::loadBuffersBinData(UInt32 buffer) {
	std::string dir = mPath.substr(0, mPath.find_last_of('/') + 1);
	std::ifstream file;

	file.open(dir + mBuffers[buffer].uri, std::ios::out | std::ios::binary);
	ASSERT(file.good());

	std::vector<char> data(std::istreambuf_iterator<char>(file), {});

	mBuffers[buffer].data.resize(data.size());

	std::copy(data.begin(), data.end(), mBuffers[buffer].data.begin());
}

void GLTF2::loadBuffersUriData(UInt32 buffer) {
	auto uriData = mBuffers[buffer].uri.substr(mBuffers[buffer].uri.find(',') + 1);
	base64::decode(uriData, mBuffers[buffer].data);
}

void GLTF2::loadBufferViews() {
	auto bufferViewsIt = mDoc.FindMember("bufferViews");
	ASSERT(bufferViewsIt != mDoc.MemberEnd());

	auto& bufferViews = bufferViewsIt->value;
	ASSERT(bufferViews.IsArray());

	mBufferViews.resize(bufferViews.Size());

	for (rj::SizeType i = 0; i < bufferViews.Size(); ++i) {
		auto bufferIt = bufferViews[i].FindMember("buffer");
		ASSERT(bufferIt != bufferViews[i].MemberEnd());

		auto& buffer = bufferIt->value;
		ASSERT(buffer.IsUint());

		mBufferViews[i].buffer = buffer.GetUint();


		auto byteOffsetIt = bufferViews[i].FindMember("byteOffset");
		ASSERT(byteOffsetIt != bufferViews[i].MemberEnd());

		auto& byteOffset = byteOffsetIt->value;
		ASSERT(byteOffset.IsUint());

		mBufferViews[i].byteOffset = byteOffset.GetUint();


		auto byteLengthIt = bufferViews[i].FindMember("byteLength");
		ASSERT(byteLengthIt != bufferViews[i].MemberEnd());

		auto& byteLength = byteLengthIt->value;
		ASSERT(byteLength.IsUint());

		mBufferViews[i].byteLength = byteLength.GetUint();


		auto byteStrideIt = bufferViews[i].FindMember("byteStride");
		if (byteStrideIt != bufferViews[i].MemberEnd()) {
			auto& byteStride = byteStrideIt->value;
			ASSERT(byteStride.IsUint());
			mBufferViews[i].byteStride = byteStride.GetUint();
		}


		auto targetIt = bufferViews[i].FindMember("target");
		if (targetIt != bufferViews[i].MemberEnd()) {
			auto& target = targetIt->value;
			ASSERT(target.IsUint());
			mBufferViews[i].target = target.GetUint();
		} else {
			mBufferViews[i].target = -1;
		}
	}
}

void GLTF2::loadMaterials() {
	auto materialsIt = mDoc.FindMember("materials");
	if (materialsIt == mDoc.MemberEnd()) { return; }

	auto& materials = materialsIt->value;
	ASSERT(materials.IsArray());

	mMaterials.resize(materials.Size());

	for (rj::SizeType material = 0; material < materials.Size(); ++material) {
		auto pbrMetallicRoughnessIt = materials[material].FindMember("pbrMetallicRoughness");
		if (pbrMetallicRoughnessIt != materials[material].MemberEnd()) {
			auto& pbrMetallicRoughness = pbrMetallicRoughnessIt->value;
			ASSERT(pbrMetallicRoughness.IsObject());

			auto nameIt = pbrMetallicRoughness.FindMember("name");
			if (nameIt != pbrMetallicRoughness.MemberEnd()) {
				auto& name = nameIt->value;
				ASSERT(name.IsString());
				mMaterials[material].name = name.GetString();
			}

			auto baseColorTextureIt = pbrMetallicRoughness.FindMember("baseColorTexture");
			if (baseColorTextureIt != pbrMetallicRoughness.MemberEnd()) {
				auto& baseColorTexture = baseColorTextureIt->value;
				ASSERT(baseColorTexture.IsObject());

				auto indexIt = baseColorTexture.FindMember("index");
				if (indexIt != baseColorTexture.MemberEnd()) {
					auto& index = indexIt->value;
					ASSERT(index.IsUint());
					mMaterials[material].pbrMetallicRoughness.baseColorTexture.index = index.GetUint();
				}
			}

			auto metallicFactorIt = pbrMetallicRoughness.FindMember("metallicFactor");
			if (metallicFactorIt != pbrMetallicRoughness.MemberEnd()) {
				auto& metallicFactor = metallicFactorIt->value;
				ASSERT(metallicFactor.IsFloat());
				mMaterials[material].pbrMetallicRoughness.metallicFactor = metallicFactor.GetFloat();
			}

			auto roughnessFactorIt = pbrMetallicRoughness.FindMember("roughnessFactor");
			if (roughnessFactorIt != pbrMetallicRoughness.MemberEnd()) {
				auto& roughnessFactor = roughnessFactorIt->value;
				ASSERT(roughnessFactor.IsFloat());
				mMaterials[material].pbrMetallicRoughness.roughnessFactor = roughnessFactor.GetFloat();
			}
		}
	}
}

void GLTF2::loadTextures() {
	auto texturesIt = mDoc.FindMember("textures");
	if (texturesIt == mDoc.MemberEnd()) { return; }

	auto& textures = texturesIt->value;
	ASSERT(textures.IsArray());

	mTextures.resize(textures.Size());

	for (rj::SizeType texture = 0; texture < textures.Size(); ++texture) {
		auto samplerIt = textures[texture].FindMember("sampler");
		if (samplerIt != textures[texture].MemberEnd()) {
			auto& sampler = samplerIt->value;
			ASSERT(sampler.IsUint());
			mTextures[texture].sampler = sampler.GetUint();
		}

		auto sourceIt = textures[texture].FindMember("source");
		if (sourceIt != textures[texture].MemberEnd()) {
			auto& source = sourceIt->value;
			ASSERT(source.IsUint());
			mTextures[texture].source = source.GetUint();
		}

		auto nameIt = textures[texture].FindMember("name");
		if (nameIt != textures[texture].MemberEnd()) {
			auto& name = nameIt->value;
			ASSERT(name.IsString());
			mTextures[texture].name = name.GetString();
		}
	}

}
void GLTF2::loadImages() {
	auto imagesIt = mDoc.FindMember("images");
	if (imagesIt == mDoc.MemberEnd()) { return; }

	auto& images = imagesIt->value;
	ASSERT(images.IsArray());

	mImages.resize(images.Size());

	for (rj::SizeType image = 0; image < images.Size(); ++image) {
		auto uriIt = images[image].FindMember("uri");
		if (uriIt != images[image].MemberEnd()) {
			auto& uri = uriIt->value;
			ASSERT(uri.IsString());
			mImages[image].uri = uri.GetString();
		}
	}
}

void GLTF2::loadSamplers() {
	auto samplersIt = mDoc.FindMember("samplers");
	if (samplersIt == mDoc.MemberEnd()) { return; }

	auto& samplers = samplersIt->value;
	ASSERT(samplers.IsArray());

	mSamplers.resize(samplers.Size());

	for (rj::SizeType sampler = 0; sampler < samplers.Size(); ++sampler) {
		auto magFilterIt = samplers[sampler].FindMember("magFilter");
		if (magFilterIt != samplers[sampler].MemberEnd()) {
			auto& magFilter = magFilterIt->value;
			ASSERT(magFilter.IsUint());
			mSamplers[sampler].magFilter = gltf2::Sampler::MagFilter(magFilter.GetUint());
		}

		auto minFilterIt = samplers[sampler].FindMember("minFilter");
		if (minFilterIt != samplers[sampler].MemberEnd()) {
			auto& minFilter = minFilterIt->value;
			ASSERT(minFilter.IsUint());
			mSamplers[sampler].minFilter = gltf2::Sampler::MinFilter(minFilter.GetUint());
		}

		auto wrapSIt = samplers[sampler].FindMember("wrapS");
		if (wrapSIt != samplers[sampler].MemberEnd()) {
			auto& wrapS = wrapSIt->value;
			ASSERT(wrapS.IsUint());
			mSamplers[sampler].wrapS = gltf2::Sampler::Wrap(wrapS.GetUint());
		}

		auto wrapTIt = samplers[sampler].FindMember("wrapT");
		if (wrapTIt != samplers[sampler].MemberEnd()) {
			auto& wrapT = wrapTIt->value;
			ASSERT(wrapT.IsUint());
			mSamplers[sampler].wrapT = gltf2::Sampler::Wrap(wrapT.GetUint());
		}
	}
}

void GLTF2::loadAccessors() {
	auto accessorsIt = mDoc.FindMember("accessors");
	ASSERT(accessorsIt != mDoc.MemberEnd());

	auto& accessors = accessorsIt->value;
	ASSERT(accessors.IsArray());

	mAccessors.resize(accessors.Size());

	for (rj::SizeType i = 0; i < accessors.Size(); ++i) {
		mAccessors[i].load(accessors[i]);
	}
}

void GLTF2::loadAsset() {
	auto assetIt = mDoc.FindMember("asset");
	ASSERT(assetIt != mDoc.MemberEnd());

	auto& asset = assetIt->value;
	ASSERT(asset.IsObject());

	mAsset.load(asset);
}

void GLTF2::loadAnimations() {
	auto animationsIt = mDoc.FindMember("animations");
	if (animationsIt == mDoc.MemberEnd()) { return; }

	auto& animations = animationsIt->value;
	ASSERT(animations.IsArray());

	mAnimations.resize(animations.Size());

	for (rj::SizeType i = 0; i < animations.Size(); ++i) {
		mAnimations[i].load(animations[i]);
	}
}

} // namespace engine
