// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <memory>

namespace engine {

class MeshTechnique {
public:
	MeshTechnique(Game* game);
	~MeshTechnique();

	void update();
private:
	Game* mGame;

	std::unique_ptr<MeshShader> mMeshShader;
};

} // namespace engine
