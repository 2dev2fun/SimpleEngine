// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include <spdlog/spdlog.h>

namespace engine {

#define LOG_CRITICAL(...) { \
	spdlog::critical("[{} {}] {}", __PRETTY_FUNCTION__, __LINE__, fmt::format(__VA_ARGS__)); exit(0); \
}

#define LOG_WARNING(...) { \
	spdlog::warn("[{} {}] {}", __PRETTY_FUNCTION__, __LINE__, fmt::format(__VA_ARGS__)); \
}

#define LOG_DEBUG(...) { \
	spdlog::debug("[{} {}] {}", __PRETTY_FUNCTION__, __LINE__, fmt::format(__VA_ARGS__)); \
}

#define LOG_INFO(...) { \
	spdlog::info("[{} {}] {}", __PRETTY_FUNCTION__, __LINE__, fmt::format(__VA_ARGS__)); \
}

} // namespace engine
