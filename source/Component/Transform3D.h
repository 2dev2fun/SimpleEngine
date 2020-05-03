// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"
#include "Math/Matrix4x4.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"

namespace engine {

class Transform3DComponent {
public:
	void init();
	void free();

	void update();

	void setTranslation(Vec3 const& translation);
	auto const& getTranslation();

	void setScale(Float32 scale);
	Float32 getScale();

	void setRotation(Quat const& rotation);
	auto const& getRotation();

	void setForward(Vec3 const& forward);
	auto const& getForward();

	void setRight(Vec3 const& right);
	auto const& getRight();

	void setWorldTransform(Mat4 const& worldTransform);
	auto const& getWorldTransform();
private:
	Bool    mRecompute;

	Vec3    mTranslation;
	Float32 mScale;
	Quat    mRotation;

	Vec3    mForward;
	Vec3    mRight;

	Mat4    mWorldTransform;
};

inline void Transform3DComponent::setTranslation(Vec3 const& translation) {
	mRecompute = true;
	mTranslation = translation;
}

inline auto const& Transform3DComponent::getTranslation() {
	return mTranslation;
}

inline void Transform3DComponent::setScale(Float32 scale) {
	mRecompute = true;
	mScale = scale;
}

inline Float32 Transform3DComponent::getScale() {
	return mScale;
}

inline void Transform3DComponent::setRotation(Quat const& rotation) {
	mRecompute = true;
	mRotation = rotation;
}

inline auto const& Transform3DComponent::getRotation() {
	return mRotation;
}

inline void Transform3DComponent::setForward(Vec3 const& forward) {
	mRecompute = true;
	mForward = forward;
}

inline auto const& Transform3DComponent::getForward() {
	return mForward;
}

inline void Transform3DComponent::setRight(Vec3 const& right) {
	mRecompute = true;
	mRight = right;
}

inline auto const& Transform3DComponent::getRight() {
	return mRight;
}

inline void Transform3DComponent::setWorldTransform(Mat4 const& worldTransform) {
	mWorldTransform = worldTransform;
}

inline auto const& Transform3DComponent::getWorldTransform() {
	return mWorldTransform;
}

} // namespace engine
