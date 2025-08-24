file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(Test ${SOURCES})
target_include_directories(Test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(Test PRIVATE GTest::gtest GTest::gtest_main)
add_test(Test Test)