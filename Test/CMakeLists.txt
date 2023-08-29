add_subdirectory(./lib/googletest-main/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES UserFixture.cpp ItemTest.cpp)
add_executable(runListsTest ${TEST_SOURCE_FILES})
target_link_libraries(runListsTest gtest gtest_main core)