// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "System/Render/Backend/OpenGL/VertexArray.h"

namespace engine {

VertexArray::VertexArray(std::vector<Float32> const& positions)
		: mDrawType(DrawType::SIMPLE)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_SHORT)
		, mCount(positions.size()) {
	UInt32 positionsSize = positions.size() * sizeof(Float32);
	UInt32 size = positionsSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset = 0;

	setPositions(positions, positionsOffset);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(std::vector<Float32> const& positions, std::vector<UInt16> const& indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_SHORT)
		, mCount(indices.size()) {
	UInt32 positionsSize = positions.size() * sizeof(Float32);
	UInt32 size = positionsSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset = 0;

	setPositions(positions, positionsOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(std::vector<Float32> const& positions, std::vector<UInt32> const& indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_INT)
		, mCount(indices.size()) {
	UInt32 positionsSize = positions.size() * sizeof(Float32);
	UInt32 size = positionsSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset = 0;

	setPositions(positions, positionsOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(
		const std::vector<Float32>& positions,
		const std::vector<Float32>& normals,
		const std::vector<Float32>& texCoords,
		const std::vector<UInt16>&  indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_SHORT)
		, mCount(indices.size())
		, mVAO(0xFFFFFFFF)
		, mVBO(0xFFFFFFFF)
		, mIBO(0xFFFFFFFF) {
	UInt32 positionsSize = positions.size() * sizeof(Float32);
	UInt32 normalsSize   = normals.size()   * sizeof(Float32);
	UInt32 texCoordsSize = texCoords.size() * sizeof(Float32);

	UInt32 size = positionsSize + normalsSize + texCoordsSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset = 0;
	UInt32 normalsOffset   = positionsOffset + positionsSize;
	UInt32 texCoordsOffset = normalsOffset   + normalsSize;

	setPositions(positions, positionsOffset);
	setNormals(normals, normalsOffset);
	setTexCoords(texCoords, texCoordsOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(
		const std::vector<Float32>& positions,
		const std::vector<Float32>& normals,
		const std::vector<Float32>& texCoords,
		const std::vector<UInt32>&  indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_INT)
		, mCount(indices.size())
		, mVAO(0xFFFFFFFF)
		, mVBO(0xFFFFFFFF)
		, mIBO(0xFFFFFFFF) {
	UInt32 positionsSize = positions.size() * sizeof(Float32);
	UInt32 normalsSize   = normals.size()   * sizeof(Float32);
	UInt32 texCoordsSize = texCoords.size() * sizeof(Float32);

	UInt32 size = positionsSize + normalsSize + texCoordsSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset = 0;
	UInt32 normalsOffset   = positionsOffset + positionsSize;
	UInt32 texCoordsOffset = normalsOffset   + normalsSize;

	setPositions(positions, positionsOffset);
	setNormals(normals, normalsOffset);
	setTexCoords(texCoords, texCoordsOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(
		const std::vector<Float32>& positions,
		const std::vector<Float32>& normals,
		const std::vector<Float32>& texCoords,
		const std::vector<Float32>& jointWeights,
		const std::vector<UInt16>&  jointIndices,
		const std::vector<UInt16>&  indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_SHORT)
		, mCount(indices.size())
		, mVAO(0xFFFFFFFF)
		, mVBO(0xFFFFFFFF)
		, mIBO(0xFFFFFFFF) {
	UInt32 positionsSize    = positions.size()    * sizeof(Float32);
	UInt32 normalsSize      = normals.size()      * sizeof(Float32);
	UInt32 texCoordsSize    = texCoords.size()    * sizeof(Float32);
	UInt32 jointWeightsSize = jointWeights.size() * sizeof(Float32);
	UInt32 jointIndicesSize = jointIndices.size() * sizeof(UInt16);

	UInt32 size = positionsSize + normalsSize + texCoordsSize + jointWeightsSize + jointIndicesSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset    = 0;
	UInt32 normalsOffset      = positionsOffset    + positionsSize;
	UInt32 texCoordsOffset    = normalsOffset      + normalsSize;
	UInt32 jointIndicesOffset = texCoordsOffset    + texCoordsSize;
	UInt32 jointWeightsOffset = jointIndicesOffset + jointIndicesSize;

	setPositions(positions, positionsOffset);
	setNormals(normals, normalsOffset);
	setTexCoords(texCoords, texCoordsOffset);
	setJointIndices(jointIndices, jointIndicesOffset);
	setJointWeights(jointWeights, jointWeightsOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::VertexArray(
		const std::vector<Float32>& positions,
		const std::vector<Float32>& normals,
		const std::vector<Float32>& texCoords,
		const std::vector<Float32>& jointWeights,
		const std::vector<UInt32>&  jointIndices,
		const std::vector<UInt32>&  indices)
		: mDrawType(DrawType::INDEX)
		, mMode(GL_TRIANGLES)
		, mType(GL_UNSIGNED_INT)
		, mCount(indices.size())
		, mVAO(0xFFFFFFFF)
		, mVBO(0xFFFFFFFF)
		, mIBO(0xFFFFFFFF) {
	UInt32 positionsSize    = positions.size()    * sizeof(Float32);
	UInt32 normalsSize      = normals.size()      * sizeof(Float32);
	UInt32 texCoordsSize    = texCoords.size()    * sizeof(Float32);
	UInt32 jointWeightsSize = jointWeights.size() * sizeof(Float32);
	UInt32 jointIndicesSize = jointIndices.size() * sizeof(UInt32);

	UInt32 size = positionsSize + normalsSize + texCoordsSize + jointWeightsSize + jointIndicesSize;

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mIBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);

	UInt32 positionsOffset    = 0;
	UInt32 normalsOffset      = positionsOffset    + positionsSize;
	UInt32 texCoordsOffset    = normalsOffset      + normalsSize;
	UInt32 jointWeightsOffset = texCoordsOffset    + texCoordsSize;
	UInt32 jointIndicesOffset = jointWeightsOffset + jointWeightsSize;

	setPositions(positions, positionsOffset);
	setNormals(normals, normalsOffset);
	setTexCoords(texCoords, texCoordsOffset);
	setJointWeights(jointWeights, jointWeightsOffset);
	setJointIndices(jointIndices, jointIndicesOffset);
	setIndices(indices);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexArray::~VertexArray() {
	if (mVAO != 0xFFFFFFFF) { glDeleteVertexArrays(1, &mVAO); mVAO = 0xFFFFFFFF; }
	if (mVBO != 0xFFFFFFFF) { glDeleteBuffers(1, &mVBO);      mVBO = 0xFFFFFFFF; }
	if (mIBO != 0xFFFFFFFF) { glDeleteBuffers(1, &mIBO);      mIBO = 0xFFFFFFFF; }
}

void VertexArray::draw() {
	glBindVertexArray(mVAO);

	switch (mDrawType) {
		case DrawType::INDEX:
			glDrawElements(mMode, mCount, mType, nullptr);
			break;
		case DrawType::SIMPLE:
			glDrawArrays(mMode, 0, mCount);
			break;
		default:
			LOG_CRITICAL("DrawType undefined!");
	}

	glBindVertexArray(0);
}

void VertexArray::setPositions(std::vector<Float32> const& positions, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, positions.size() * sizeof(Float32), &positions[0]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Float32), reinterpret_cast<void*>(offset));
}

void VertexArray::setNormals(std::vector<Float32> const& normals, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, normals.size() * sizeof(Float32), &normals[0]);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Float32), reinterpret_cast<void*>(offset));
}

void VertexArray::setTexCoords(std::vector<Float32> const& texCoords, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, texCoords.size() * sizeof(Float32), &texCoords[0]);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(Float32), reinterpret_cast<void*>(offset));
}

void VertexArray::setJointIndices(std::vector<UInt16> const& jointIndices, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, jointIndices.size() * sizeof(UInt16), &jointIndices[0]);
	glEnableVertexAttribArray(3);
	glVertexAttribIPointer(3, 4, GL_UNSIGNED_SHORT, 4 * sizeof(UInt16), reinterpret_cast<void*>(offset));
}

void VertexArray::setJointIndices(std::vector<UInt32> const& jointIndices, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, jointIndices.size() * sizeof(UInt32), &jointIndices[0]);
	glEnableVertexAttribArray(3);
	glVertexAttribIPointer(3, 4, GL_UNSIGNED_BYTE, 4 * sizeof(UInt32), reinterpret_cast<void*>(offset));
}

void VertexArray::setJointWeights(std::vector<Float32> const& jointWeights, UInt32 offset) {
	glBufferSubData(GL_ARRAY_BUFFER, offset, jointWeights.size() * sizeof(Float32), &jointWeights[0]);
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(Float32), reinterpret_cast<void*>(offset));
}

void VertexArray::setIndices(std::vector<UInt16> const& indices) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(UInt16), &indices[0], GL_STATIC_DRAW);
}

void VertexArray::setIndices(std::vector<UInt32> const& indices) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(UInt32), &indices[0], GL_STATIC_DRAW);
}

} // namespace engine
