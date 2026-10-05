

cmake_minimum_required(VERSION 3.20)
project(slankengine LANGUAGES C CXX)


option(ENGINE_FETCH_DEPS "Download dependencies if not found" ON)


#Getting SDL3. Stays quiet for further dive to find dependency
find_package(SDL3 QUIET)


if (NOT SDL3_FOUND)

    if (ENGINE_FETCH_DEPS)
        include(FetchContent)
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

find_package(glm CONFIG QUIET)

if (NOT glm_FOUND)
    if (ENGINE_FETCH_DEPS)
        include(FetchContent)
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


add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PRIVATE external/glad/include)


add_library(slankengine
    src/slankengine.cpp
)

target_include_directories(slankengine PUBLIC include)
target_include_directories(slankengine PRIVATE external/glad/include)

#privately added libraries for glad and sdl3
target_link_libraries(slankengine PRIVATE SDL3::SDL3)

#linking libs to the engine
target_link_libraries(slankengine PRIVATE glad)
target_link_libraries(slankengine PRIVATE glm::glm)

target_compile_features(slankengine PUBLIC cxx_std_20)




