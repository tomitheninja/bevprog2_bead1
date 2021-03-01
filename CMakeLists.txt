cmake_minimum_required(VERSION 3.7)
project(bevprog2)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# SDL2
set(SDL2_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2-2.0.14/x86_64-w64-mingw32/")
find_package(SDL2 REQUIRED)

# SDL2_TTF
set(SDL2_TTF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2_ttf-2.0.15/x86_64-w64-mingw32/")
find_package(SDL2_ttf REQUIRED)

# ITK_Graphics
add_library(itk_graphics external/ITK_graphics/graphics.cpp)
target_link_libraries(itk_graphics SDL2::Core SDL2::Main SDL2::TTF)

# My App

## compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

## source files
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/vector_2.cpp src/vector_2.h src/color.cpp src/color.h)

## dependencies
target_link_libraries(${CMAKE_PROJECT_NAME} itk_graphics)
include_directories(external/ITK_graphics)

## static files
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
