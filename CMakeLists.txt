cmake_minimum_required(VERSION 3.1.0)

project(SimpleEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/library")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")

add_executable(${PROJECT_NAME} "${SRC_DIR}/Main.cpp")

include_directories(${INC_DIR})

add_library(library
	"${SRC_DIR}/Game.cpp")

target_link_libraries(${PROJECT_NAME} library)
