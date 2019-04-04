# ./app/CMakeLists.txt

project(KeyloggerAPP
        VERSION 1.0.0
        DESCRIPTION "Advanced Keylogger app."
)



add_executable(Keylogger)
target_sources(Keylogger PRIVATE "main.cpp")

# Add -mwindows in executable to stop app window popping up or hide window
target_link_options(Keylogger BEFORE PRIVATE "-mwindows")
