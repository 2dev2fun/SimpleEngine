# Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

cmake_minimum_required(VERSION 3.1.0)

project(SimpleEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

add_executable(${PROJECT_NAME} "source/Main.cpp")

include_directories(
	"source"
	"library/catch2/include"
	"library/glad/include"
	"modules/glfw/include"
	"modules/rapidjson/include"
	"modules/spdlog/include"
	"modules/stb")

add_library(ProjectLib INTERFACE)
target_link_libraries(${PROJECT_NAME} ProjectLib)

# OpenGL

find_package(OpenGL REQUIRED)
target_link_libraries(ProjectLib INTERFACE OpenGL::GL)

# GLAD

add_library(glad "library/glad/include/glad/glad.h" "library/glad/src/glad.c")

# GLFW

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(modules/glfw)

# Spdlog

add_subdirectory(modules/spdlog)
target_link_libraries(ProjectLib INTERFACE spdlog::spdlog)

# SimpleEngine

add_subdirectory(source)
add_subdirectory(test)
