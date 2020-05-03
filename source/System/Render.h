// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"

#include <memory>

namespace engine {

class RenderSystem {
public:
	enum class CameraType {
		Follow,
		FPS,
		Orbit,
	};

	RenderSystem(Game* game);
	~RenderSystem();

	void update();
	void camera(CameraType type);

	void setView(Mat4 const& view);
	auto const& getView() const;

	void setProjection(Mat4 const& projection);
	auto const& getProjection() const;
private:
	Game* mGame;

	Mat4 mView;
	Mat4 mProjection;

	CameraType              mCameraType;
	std::unique_ptr<Camera> mCamera;

	std::unique_ptr<MeshTechnique> mMeshTechnique;
};

inline void RenderSystem::setView(Mat4 const& view) {
	mView = view;
}

inline auto const& RenderSystem::getView() const {
	return mView;
}

inline void RenderSystem::setProjection(Mat4 const& projection) {
	mProjection = projection;
}

inline auto  const& RenderSystem::getProjection() const {
	return mProjection;
}

} // namespace engine
