// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>

#define ASSERT(X) assert(X)

#define LOG_ERROR(X) error(__PRETTY_FUNCTION__, __LINE__, X);

namespace engine {

using Char = char;
using Bool = bool;

using Int8  = std::int8_t;
using Int16 = std::int16_t;
using Int32 = std::int32_t;
using Int64 = std::int64_t;

using UInt8  = std::uint8_t;
using UInt16 = std::uint16_t;
using UInt32 = std::uint32_t;
using UInt64 = std::uint64_t;

using Float32 = float;
using Float64 = double;

inline void trace(const Char* function, UInt32 line) {
	std::cout << "[\033[96m" << function << " " << line << "\033[0m]" << std::endl;
}

inline void error(const std::string function, UInt32 line, const std::string text) {
	std::cout << text << std::endl;
	std::cout << "[\033[96m" << function << " " << line << "\033[0m]" << std::endl;
}

} // namespace engine
