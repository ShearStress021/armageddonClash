cmake_minimum_required(VERSION 3.10)
project(armageddon VERSION 1.0 LANGUAGES CXX)


# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(raylib REQUIRED)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(res ${SOURCES})



target_link_libraries(res PRIVATE raylib)
