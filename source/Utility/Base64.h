// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine.h"

#include <string>
#include <vector>

namespace engine {
namespace base64 {

std::string encode(UInt8 const* buffer, UInt32 buflen);
void decode(std::string const& text, std::vector<UInt8>& data);

} // namespace base64
} // namespace engine
