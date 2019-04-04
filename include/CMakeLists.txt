# ./include/CMakeLists.txt
project(Headers)

add_library(include
        headers/Base64.h
        headers/Helper.h
        headers/IO.h
        headers/KeyConstrants.h
)

target_include_directories(include PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")
set_target_properties(include PROPERTIES LINKER_LANGUAGE CXX)

