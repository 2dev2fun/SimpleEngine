// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Shader/Mesh.h"
#include "System/Render/Technique/Mesh.h"

#include <memory>

using namespace engine;

MeshTechnique::MeshTechnique(Game* game) : mGame(game) {
	mMeshShader = std::make_unique<MeshShader>();
}

MeshTechnique::~MeshTechnique() {}

void MeshTechnique::update() {
	//mMeshShader->active();
}
