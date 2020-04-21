// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine/Alias.h"
#include "Engine/Forward.h"

#include <cassert>
#include <iostream>

#define UNUSED(X) do { (void)(X); } while(0)

#define ASSERT(X) assert(X)

#define LOG_ERROR(X) error(__PRETTY_FUNCTION__, __LINE__, X);

namespace engine {

inline void trace(const Char* function, UInt32 line) {
	std::cout << "[\033[96m" << function << " " << line << "\033[0m]" << std::endl;
}

inline void error(const std::string function, UInt32 line, const std::string text) {
	std::cout << text << std::endl;
	std::cout << "[\033[96m" << function << " " << line << "\033[0m]" << std::endl;
}

} // namespace engine
