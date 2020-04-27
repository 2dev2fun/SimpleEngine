// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <glad/glad.h>

#include <vector>

namespace engine {

class VertexArray {
public:
	VertexArray(
			const std::vector<Float32>& positions,
			const std::vector<Float32>& normals,
			const std::vector<Float32>& texCoords,
			const std::vector<UInt16>&  indices);

	VertexArray(
			const std::vector<Float32>& positions,
			const std::vector<Float32>& normals,
			const std::vector<Float32>& texCoords,
			const std::vector<UInt32>&  indices);

	VertexArray(
			const std::vector<Float32>& positions,
			const std::vector<Float32>& normals,
			const std::vector<Float32>& textureCoordinates,
			const std::vector<Float32>& jointWeights,
			const std::vector<UInt16>&  jointIndices,
			const std::vector<UInt16>&  indices);

	VertexArray(
			const std::vector<Float32>& positions,
			const std::vector<Float32>& normals,
			const std::vector<Float32>& textureCoordinates,
			const std::vector<Float32>& jointWeights,
			const std::vector<UInt32>&  jointIndices,
			const std::vector<UInt32>&  indices);

	~VertexArray();

	void draw();
protected:
	void setPositions(std::vector<Float32> const& positions, UInt32 offset);
	void setNormals(std::vector<Float32> const& normals, UInt32 offset);
	void setTexCoords(std::vector<Float32> const& texCoords, UInt32 offset);
	void setJointWeights(std::vector<Float32> const& jointWeights, UInt32 offset);
	void setJointIndices(std::vector<UInt16> const& jointIndices, UInt32 offset);
	void setJointIndices(std::vector<UInt32> const& jointIndices, UInt32 offset);

	void setIndices(std::vector<UInt16> const& indices);
	void setIndices(std::vector<UInt32> const& indices);
private:
	GLenum mType;
	GLsizei mCount;

	GLuint mVAO;
	GLuint mVBO;
	GLuint mIBO;
};

} // namespace engine
