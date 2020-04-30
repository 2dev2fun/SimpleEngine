// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "System/Render/Primitive.h"

#include <memory>
#include <string>
#include <vector>

namespace engine {

class Mesh {
public:
	Mesh(std::string const& path);
	~Mesh();

	void draw();

	void setPrimivites(std::vector<Primitive> primitives);
	auto getPrimitives();
private:
	std::vector<Primitive> mPrimitives;
};

inline void Mesh::setPrimivites(std::vector<Primitive> primitives) {
	mPrimitives = primitives;
}

inline auto Mesh::getPrimitives() {
	return mPrimitives;
}

inline void Mesh::draw() {
	for (auto& primitive : mPrimitives) { primitive.draw(); }
}

} // namespace engine
