// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

class MoveComponent {
public:
	void init();
	void free();

	void update();

	void setAngularSpeed(Float32 value);
	auto getAngularSpeed() const;

	void setAngularValue(Float32 value);
	auto getAngularValue() const;

	void setForwardSpeed(Float32 value);
	auto getForwardSpeed() const;

	void setForwardValue(Float32 value);
	auto getForwardValue() const;

	void setStrafeSpeed(Float32 value);
	auto getStrafeSpeed() const;

	void setStrafeValue(Float32 value);
	auto getStrafeValue() const;
private:
	Float32 mAngularSpeed;
	Float32 mAngularValue;

	Float32 mForwardSpeed;
	Float32 mForwardValue;

	Float32 mStrafeSpeed;
	Float32 mStrafeValue;
};

inline void MoveComponent::setAngularSpeed(Float32 value) {
	mAngularSpeed = value;
}

inline auto MoveComponent::getAngularSpeed() const {
	return mAngularSpeed;
}

inline void MoveComponent::setAngularValue(Float32 value) {
	mAngularValue = value;
}

inline auto MoveComponent::getAngularValue() const {
	return mAngularValue;
}

inline void MoveComponent::setForwardSpeed(Float32 value) {
	mForwardSpeed = value;
}

inline auto MoveComponent::getForwardSpeed() const {
	return mForwardSpeed;
}

inline void MoveComponent::setForwardValue(Float32 value) {
	mForwardValue = value;
}

inline auto MoveComponent::getForwardValue() const {
	return mForwardValue;
}

inline void MoveComponent::setStrafeSpeed(Float32 value) {
	mStrafeSpeed = value;
}

inline auto MoveComponent::getStrafeSpeed() const {
	return mStrafeSpeed;
}

inline void MoveComponent::setStrafeValue(Float32 value) {
	mStrafeValue = value;
}

inline auto MoveComponent::getStrafeValue() const {
	return mStrafeValue;
}

} // namespace engine
