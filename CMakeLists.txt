# ./CMakeLists.txt
cmake_minimum_required(VERSION 3.13.0)

project(Keylogger_CMake)


# always add library first then executable
add_subdirectory(include)
add_subdirectory(src)