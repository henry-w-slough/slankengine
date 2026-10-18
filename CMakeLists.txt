cmake_minimum_required(VERSION 3.20)
project(slankengine LANGUAGES C CXX)

option(ENGINE_FETCH_DEPS "Download dependencies if not found" ON)

include(FetchContent)


#allows sdl3 to be reused if it's found seperately
if(NOT TARGET SDL3::SDL3)
    find_package(SDL3 QUIET)

    if(NOT SDL3_FOUND)
        if(ENGINE_FETCH_DEPS)
            FetchContent_Declare(
                SDL3
                GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
                GIT_TAG release-3.2.0
            )
            FetchContent_MakeAvailable(SDL3)
        else()
            message(FATAL_ERROR "SLANKENGINE FAILURE: SDL3 not found, install it or set ENGINE_FETCH_DEPS=ON.")
        endif()
    endif()
endif()


if(NOT TARGET spdlog::spdlog)
    find_package(spdlog CONFIG QUIET)

    if(NOT spdlog_FOUND)
        if(ENGINE_FETCH_DEPS)
            FetchContent_Declare(
                spdlog
                GIT_REPOSITORY https://github.com/gabime/spdlog.git
                GIT_TAG v1.15.3
            )
            FetchContent_MakeAvailable(spdlog)
        else()
            message(FATAL_ERROR "SLANKENGINE FAILURE: spdlog not found, install it or set ENGINE_FETCH_DEPS=ON.")
        endif()
    endif()
endif()


if(NOT TARGET glm::glm)
    find_package(glm CONFIG QUIET)

    if(NOT glm_FOUND)
        if(ENGINE_FETCH_DEPS)
            FetchContent_Declare(
                glm
                GIT_REPOSITORY https://github.com/g-truc/glm.git
                GIT_TAG 1.0.1
            )
            FetchContent_MakeAvailable(glm)
        else()
            message(FATAL_ERROR "SLANKENGINE FAILURE: GLM not found, install it or set ENGINE_FETCH_DEPS=ON.")
        endif()
    endif()
endif()


# glad is supplied in-framework
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)


add_library(slankengine
    src/slankengine/core.cpp
    src/utility/logging.cpp
    src/window/window.cpp
    src/rendering/renderer.cpp
    src/rendering/mesh_data.cpp
    src/rendering/mesh.cpp
    src/rendering/shader.cpp
    src/rendering/shader_data.cpp
)

target_include_directories(slankengine PUBLIC include)

target_link_libraries(slankengine
    PUBLIC  glm::glm spdlog::spdlog # types from public headers
    PRIVATE SDL3::SDL3 glad   # hidden from the game
)

target_compile_features(slankengine PUBLIC cxx_std_20)


