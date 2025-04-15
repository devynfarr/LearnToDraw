# CMakeList.txt : CMake project for LearnToDraw, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(APP_DIR "${CMAKE_CURRENT_LIST_DIR}"
	CACHE PATH "Application directory")

set(BLEND2D_DIR "${APP_DIR}/../blend2d"
	CACHE PATH "Location of 'blend2d'")

set(BLEND2D_STATIC TRUE)

include("${BLEND2D_DIR}/CMakeLists.txt")
# Add source to this project's executable.
add_executable (LearnToDraw "LearnToDraw.cpp" "LearnToDraw.h")

target_link_libraries(LearnToDraw Blend2D::Blend2D)
# TODO: Add tests and install targets if needed.
