// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Engine/Alias.h"
#include "Engine/Forward.h"
#include "Engine/Logger.h"

#include <cassert>

#undef NDEBUG

#define UNUSED(X) do { (void)(X); } while(0)
#define ASSERT(X) assert(X)
