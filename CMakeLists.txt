cmake_minimum_required (VERSION 3.20)

project("OTemplate")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(dependencies.cmake)

add_subdirectory(src)
add_subdirectory(test)