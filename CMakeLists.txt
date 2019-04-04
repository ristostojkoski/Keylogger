# ./CMakeLists.txt
cmake_minimum_required(VERSION 3.13.0)

project(Keylogger_CMake
        VERSION 1.0.0
        DESCRIPTION "Advanced Keylogger Udemy Course built with CMake")



# Create targets for building the (local) libraries.
add_subdirectory(include)

# Create the targets for the entire app.
add_subdirectory(app)

