// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include <memory>

namespace engine {

class Primitive {
public:
	Primitive();
	~Primitive();

	void draw();

	void setAlbedoTexture(std::shared_ptr<Texture> texture);
	auto getAlbedoTexture();

	void setAmbientOcclusionTexture(std::shared_ptr<Texture> texture);
	auto getAmbientOcclusionTexture();

	void setEmissionTexture(std::shared_ptr<Texture> texture);
	auto getEmissionTexture();

	void setMetallicTexture(std::shared_ptr<Texture> texture);
	auto getMetallicTexture();

	void setNormalTexture(std::shared_ptr<Texture> texture);
	auto getNormalTexture();

	void setRoughnessTexture(std::shared_ptr<Texture> texture);
	auto getRoughnessTexture();

	void setVertexArray(std::shared_ptr<VertexArray> vertexArray);
	auto getVertexArray();
private:
	std::shared_ptr<Texture>     mAlbedoTexture;
	std::shared_ptr<Texture>     mAmbientOcclusionTexture;
	std::shared_ptr<Texture>     mEmissionTexture;
	std::shared_ptr<Texture>     mMetallicTexture;
	std::shared_ptr<Texture>     mNormalTexture;
	std::shared_ptr<Texture>     mRoughnessTexture;
	std::shared_ptr<VertexArray> mVertexArray;
};

inline void Primitive::setAlbedoTexture(std::shared_ptr<Texture> texture) {
	mAlbedoTexture = texture;
}

inline auto Primitive::getAlbedoTexture() {
	return mAlbedoTexture;
}

inline void Primitive::setAmbientOcclusionTexture(std::shared_ptr<Texture> texture) {
	mAmbientOcclusionTexture = texture;
}

inline auto Primitive::getAmbientOcclusionTexture() {
	return mAmbientOcclusionTexture;
}

inline void Primitive::setEmissionTexture(std::shared_ptr<Texture> texture) {
	mEmissionTexture = texture;
}

inline auto Primitive::getEmissionTexture() {
	return mEmissionTexture;
}

inline void Primitive::setMetallicTexture(std::shared_ptr<Texture> texture) {
	mEmissionTexture = texture;
}

inline auto Primitive::getMetallicTexture() {
	return mMetallicTexture;
}

inline void Primitive::setNormalTexture(std::shared_ptr<Texture> texture) {
	mNormalTexture = texture;
}

inline auto Primitive::getNormalTexture() {
	return mNormalTexture;
}

inline void Primitive::setRoughnessTexture(std::shared_ptr<Texture> texture) {
	mRoughnessTexture = texture;
}

inline auto Primitive::getRoughnessTexture() {
	return mRoughnessTexture;
}

inline void Primitive::setVertexArray(std::shared_ptr<VertexArray> vertexArray) {
	mVertexArray = vertexArray;
}

inline auto Primitive::getVertexArray() {
	return mVertexArray;
}

} // namespace engine
