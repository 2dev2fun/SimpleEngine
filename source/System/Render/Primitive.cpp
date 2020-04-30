// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/Texture.h"
#include "System/Render/Backend/OpenGL/VertexArray.h"
#include "System/Render/Primitive.h"

namespace engine {

Primitive::Primitive() {}

Primitive::~Primitive() {}

void Primitive::draw() {
	//mAlbedoTexture->bind(0);
	//mAmbientOcclusionTexture->bind(1);
	//mEmissionTexture->bind(2);
	//mNormalTexture->bind(3);
	//mRoughnessTexture->bind(4);
	//mMetallicTexture->bind(5);
	mVertexArray->draw();
}

} // namespace engine
