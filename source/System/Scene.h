// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

class SceneSystem {
public:
	SceneSystem(Game* game);
	~SceneSystem();

	void update();
private:
	Game* mGame;
};

} // namespace engine
