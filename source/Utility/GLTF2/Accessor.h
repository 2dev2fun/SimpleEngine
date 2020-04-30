// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <rapidjson/document.h>

namespace rj = rapidjson;

namespace engine {
namespace gltf2 {

class Accessor {
public:
	enum class ComponentType {
		NONE   = 0,
		BYTE   = 5120,
		UBYTE  = 5121,
		SHORT  = 5122,
		USHORT = 5123,
		UINT   = 5125,
		FLOAT  = 5126,
	};

	enum class Type {
		NONE   = 0,
		SCALAR = 1,
		VEC2   = 2,
		VEC3   = 3,
		VEC4   = 4,
		MAT2   = 5,
		MAT3   = 6,
		MAT4   = 7,
	};

	class Sparse {
	public:
		class Indices {
		public:
			void load(rj::Value& indices);

			Bool hasBufferView() const;
			auto getBufferView() const;

			auto getByteOffset() const;

			Bool hasComponentType() const;
			auto getComponentType() const;
		private:
			Int32         mBufferView    = -1;
			UInt32        mByteOffset    =  0;
			ComponentType mComponentType = ComponentType::NONE;
		};

		class Values {
		public:
			void load(rj::Value& values);

			Bool hasBufferView() const;
			auto getBufferView() const;

			auto getByteOffset() const;
		private:
			Int32  mBufferView = -1;
			UInt32 mByteOffset =  0;
		};

		void load(rj::Value& sparse);

		Bool hasCount() const;
		auto getCount() const;

		auto const& getIndices() const;
		auto const& getValues() const;
	private:
		Int32   mCount   = -1;
		Indices mIndices;
		Values  mValues;
	};

	void load(rj::Value& accessor);

	Bool hasBufferView() const;
	auto getBufferView() const;

	auto getByteOffset() const;

	Bool hasComponentType(ComponentType componentType) const;
	auto getComponentType() const;

	Bool hasCount() const;
	auto getCount() const;

	Bool hasType(Type type) const;
	auto getType() const;

	Bool hasMax() const;
	auto const& getMax() const;

	Bool hasMin() const;
	auto const& getMin() const;

	auto const& getSparse() const;
private:
	Int32                mBufferView    = -1;
	UInt32               mByteOffset    =  0;
	ComponentType        mComponentType = ComponentType::NONE;
	Int32                mCount         = -1;
	Type                 mType          = Type::NONE;
	std::vector<Float32> mMax;
	std::vector<Float32> mMin;
	Sparse               mSparse;
};

inline Bool Accessor::hasType(Type type) const {
	return mType == type;
}

inline auto Accessor::getType() const {
	return mType;
}

inline Bool Accessor::hasComponentType(ComponentType componentType) const {
	return mComponentType == componentType;
}

inline auto Accessor::getComponentType() const {
	return mComponentType;
}

inline Bool Accessor::hasBufferView() const {
	return mBufferView >= 0;
}

inline auto Accessor::getBufferView() const {
	ASSERT(hasBufferView());
	return mBufferView;
}

inline auto Accessor::getByteOffset() const {
	return mByteOffset;
}

inline bool Accessor::hasCount() const {
	return mCount > 0;
}

inline auto Accessor::getCount() const {
	ASSERT(hasCount());
	return mCount;
}

inline Bool Accessor::hasMax() const {
	return mMax.size() > 0;
}

inline auto const& Accessor::getMax() const {
	ASSERT(hasMax());
	return mMax;
}

inline Bool Accessor::hasMin() const {
	return mMin.size() > 0;
}

inline auto const& Accessor::getMin() const {
	ASSERT(hasMin());
	return mMin;
}

inline auto const& Accessor::getSparse() const {
	return mSparse;
}

inline Bool Accessor::Sparse::hasCount() const {
	return mCount > 0;
}

inline auto Accessor::Sparse::getCount() const {
	ASSERT(hasCount());
	return mCount;
}

inline auto const& Accessor::Sparse::getIndices() const {
	return mIndices;
}

inline auto const& Accessor::Sparse::getValues() const {
	return mValues;
}

inline Bool Accessor::Sparse::Indices::hasBufferView() const {
	return mBufferView >= 0;
}

inline auto Accessor::Sparse::Indices::getBufferView() const {
	ASSERT(hasBufferView());
	return mBufferView;
}

inline auto Accessor::Sparse::Indices::getByteOffset() const {
	return mByteOffset;
}

inline Bool Accessor::Sparse::Indices::hasComponentType() const {
	return mComponentType != ComponentType::NONE;
}

inline auto Accessor::Sparse::Indices::getComponentType() const {
	ASSERT(hasComponentType());
	return mComponentType;
}

inline Bool Accessor::Sparse::Values::hasBufferView() const {
	return mBufferView >= 0;
}

inline auto Accessor::Sparse::Values::getBufferView() const {
	ASSERT(hasBufferView());
	return mBufferView;
}

inline auto Accessor::Sparse::Values::getByteOffset() const {
	return mByteOffset;
}

} // namespace gltf2
} // namespace engine
