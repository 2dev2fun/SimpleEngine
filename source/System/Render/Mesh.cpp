// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Texture.h"
#include "System/Render/Backend/OpenGL/VertexArray.h"
#include "System/Render/Mesh.h"
#include "Utility/GLTF2.h"

#include <string>

namespace engine {

Mesh::Mesh(std::string const& path) {
	GLTF2 gltf2(path);
	gltf2.fillMesh(this);

	//enum {
		//HAS_POSITIONS = 1 << 0,
		//HAS_NORMALS   = 1 << 1,
		//HAS_TEXCOORDS = 1 << 2,
		//HAS_INDICES   = 1 << 3,
	//};

	//for (UInt32 node = 0; node < mNodes.size(); ++node) {
		//if (mNodes[node].mesh >= 0) {
			//UInt32 mesh = mNodes[node].mesh;
			//for (UInt32 primitive = 0; primitive < mMeshes[mesh].primitives.size(); ++primitive) {
				//Mask mask = 0;

				//std::vector<Float32> positions;
				//std::vector<Float32> normals;
				//std::vector<UInt16> indices16;

				//if (mMeshes[mesh].primitives[primitive].attribute.POSITION >= 0) {
					//mask |= HAS_POSITIONS;
					//positions = getPositions(mesh, primitive);
				//} else {
					//LOG_CRITICAL("mMeshes[{}].primitives[{}].attribute.POSITION >= 0", mesh, primitive);
				//}

				//switch (mask) {
					//case HAS_POSITIONS:
						//mMeshResources.emplace_back(std::make_shared<MeshResource>());
						//mMeshResources.back()->setVertexArray(std::make_shared<VertexArray>(positions));
						//break;

					//default:
						//LOG_CRITICAL("Wrong mask");
				//}
			//}
		//}
	//}

}

Mesh::~Mesh() {}

} // namespace engine
