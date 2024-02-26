cmake_minimum_required(VERSION 3.27)
project(CPP-project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPP-project
        main.cpp
)

add_subdirectory(libs/libfort)
add_subdirectory(libs/termcolor)

target_link_libraries(CPP-project PRIVATE fort)
target_link_libraries(CPP-project PRIVATE termcolor)