cmake_minimum_required(VERSION 3.15)
project(mainGame LANGUAGES CXX)

# 1. Create the game executable
add_executable(main src/main.cpp)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_compile_definitions(main PRIVATE SDL_MAIN_HANDLED)
if(WIN32)
	target_link_options(main PRIVATE -mconsole)
endif()

# 2. Link your engine package. 
# CMake handles all header paths and binaries automatically behind the scenes!
target_link_libraries(main PRIVATE slankengine)
