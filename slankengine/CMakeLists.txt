cmake_minimum_required(VERSION 3.15)
# Added C language support since glad.c needs a C compiler
project(slankengine LANGUAGES C CXX)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

# ==============================================================================
# 1. CREATE AND CONFIG GLAD FIRST
# ==============================================================================
# Fix: Tell CMake to compile glad.c as a static library target
add_library(glad STATIC external/glad/src/glad.c)

# Provide GLAD headers to itself and any target that links to it
target_include_directories(glad PUBLIC "external/glad/include")

# Linux/macOS require dynamic loader flags for glad to function
if(NOT WIN32)
    target_link_libraries(glad INTERFACE ${CMAKE_DL_LIBS})
endif()

# ==============================================================================
# 2. CREATE AND CONFIG SLANKENGINE
# ==============================================================================
add_library(slankengine
    src/core.cpp
    src/rendering/screen.cpp
)

include(FetchContent)

FetchContent_Declare(SDL3 GIT_REPOSITORY https://github.com/libsdl-org/SDL.git GIT_TAG release-3.2.0)
FetchContent_Declare(glm  GIT_REPOSITORY https://github.com/g-truc/glm.git     GIT_TAG 1.0.1)

FetchContent_MakeAvailable(SDL3 glm)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 glm::glm)



target_include_directories(slankengine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(slankengine PRIVATE glad)
target_link_libraries(slankengine PUBLIC SDL3::SDL3 SDL3_image::SDL3_image)
target_compile_features(slankengine PUBLIC cxx_std_17)

add_library(slankengine::slankengine ALIAS slankengine)
