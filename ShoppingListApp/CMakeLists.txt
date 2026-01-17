cmake_minimum_required(VERSION 3.14)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

project(ShoppingListApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest-main)

add_executable(runTests
    tests/CategoryTest.cpp
    tests/ShoppingItemTest.cpp
    tests/ShoppingListTest.cpp
    tests/ObserverTest.cpp
    tests/SharedListTest.cpp
)

target_include_directories(runTests PRIVATE src)
target_link_libraries(runTests PRIVATE gtest gtest_main)
