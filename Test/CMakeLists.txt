cmake_minimum_required(VERSION 3.15)

add_subdirectory(./lib/googletest-main/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp UserFixture.cpp ItemTest.cpp ShoppingListFixture.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)