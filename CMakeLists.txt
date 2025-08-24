cmake_minimum_required (VERSION 3.20)

project ("OTemplate")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(dependencies.cmake)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(OTemplate INTERFACE)
target_sources(OTemplate INTERFACE ${HEADERS})
target_include_directories(OTemplate INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:OTemplate>
)

add_subdirectory(test)