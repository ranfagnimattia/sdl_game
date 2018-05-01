cmake_minimum_required(VERSION 3.9)
project(ProvaSDL)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})
set(SDL_LIBRARY_TEMP ${SDL2_LIBRARY})



add_executable(ProvaSDL main.cpp Game.cpp Game.h TextureManager.h TextureManager.cpp GameObject.cpp GameObject.h)
target_link_libraries(ProvaSDL ${SDL2_LIBRARY_TEMP} ${SDL2_IMAGE_LIBRARIES})

