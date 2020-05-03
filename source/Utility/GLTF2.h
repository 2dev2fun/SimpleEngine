// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Utility/GLTF2/Accessor.h"
#include "Utility/GLTF2/Animation.h"
#include "Utility/GLTF2/Asset.h"
#include "Utility/GLTF2/Buffer.h"
#include "Utility/GLTF2/BufferView.h"
#include "Utility/GLTF2/Camera.h"
#include "Utility/GLTF2/Image.h"
#include "Utility/GLTF2/Material.h"
#include "Utility/GLTF2/Mesh.h"
#include "Utility/GLTF2/Node.h"
#include "Utility/GLTF2/Sampler.h"
#include "Utility/GLTF2/Scene.h"
#include "Utility/GLTF2/Skin.h"
#include "Utility/GLTF2/Texture.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace rj = rapidjson;

namespace engine {

class GLTF2 {
public:
	GLTF2(std::string const& path);
	~GLTF2();

	void fillMesh(Mesh* mesh);
private:
	void loadAccessors();
	void loadAnimations();
	void loadBuffers();
	void loadAsset();
	void loadBufferViews();
	void loadMeshes();
	void loadNodes();
	void loadScenes();
	void loadSamplers();
	void loadSkins();
	void loadImages();
	void loadTextures();
	void loadMaterials();

	std::vector<Float32> getPositions(UInt32 mesh, UInt32 primitive);
	std::vector<Float32> getTexCoord0(UInt32 mesh, UInt32 primitive);
	std::vector<Float32> getTexCoord1(UInt32 mesh, UInt32 primitive);
	std::vector<Float32> getWeights(UInt32 mesh, UInt32 primitive);
	std::vector<UInt16>  getJoints16(UInt32 mesh, UInt32 primitive);
	std::vector<UInt32>  getJoints32(UInt32 mesh, UInt32 primitive);
	std::vector<UInt16>  getIndices16(UInt32 mesh, UInt32 primitive);
	std::vector<UInt32>  getIndices32(UInt32 mesh, UInt32 primitive);

	void loadBuffersBinData(UInt32 buffer);
	void loadBuffersUriData(UInt32 buffer);

	UInt32 getComponentTypeElements(const std::string& type);
	UInt32 getComponentTypeBytes(UInt32 type);

	rj::Document mDoc;
	std::string mPath;

	std::vector<gltf2::Scene>      mScenes;
	std::vector<gltf2::Node>       mNodes;
	std::vector<gltf2::Mesh>       mMeshes;
	std::vector<gltf2::Buffer>     mBuffers;
	std::vector<gltf2::BufferView> mBufferViews;
	std::vector<gltf2::Animation>  mAnimations;
	std::vector<gltf2::Accessor>   mAccessors;
	std::vector<gltf2::Camera>     mCameras;
	std::vector<gltf2::Sampler>    mSamplers;
	std::vector<gltf2::Image>      mImages;
	std::vector<gltf2::Texture>    mTextures;
	std::vector<gltf2::Material>   mMaterials;
	std::vector<gltf2::Skin>       mSkins;

	gltf2::Asset mAsset;
};

} // namespace engine
