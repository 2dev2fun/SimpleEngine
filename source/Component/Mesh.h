// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

namespace engine {

class MeshComponent {
public:
	void init();
	void free();

	void update();

	void setData1(Float32 data);
	auto getData1() const;

	void setData2(Float32 data);
	auto getData2() const;
private:
	Float32 mData1;
	Float32 mData2;
};

inline void MeshComponent::setData1(Float32 data) {
	mData1 = data;
}

inline auto MeshComponent::getData1() const {
	return mData1;
}

inline void MeshComponent::setData2(Float32 data) {
	mData2 = data;
}

inline auto MeshComponent::getData2() const {
	return mData2;
}

} // namespace engine
