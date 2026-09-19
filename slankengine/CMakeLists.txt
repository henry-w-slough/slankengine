cmake_minimum_required(VERSION 3.15)
project(slankengine LANGUAGES CXX)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

add_library(slankengine
    src/core.cpp
    src/rendering/screen.cpp
)

target_include_directories(slankengine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(slankengine PUBLIC SDL3::SDL3 SDL3_image::SDL3_image)
target_compile_features(slankengine PUBLIC cxx_std_17)

add_library(slankengine::slankengine ALIAS slankengine)
