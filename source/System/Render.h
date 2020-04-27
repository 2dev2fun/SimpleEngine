// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <memory>

namespace engine {

class RenderSystem {
public:
	RenderSystem(Game* game);
	~RenderSystem();

	void update();
private:
	Game* mGame;

	std::unique_ptr<MeshTechnique> mMeshTechnique;
};

} // namespace engine
