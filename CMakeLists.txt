cmake_minimum_required(VERSION 3.27)
project(CPP-project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPP-project
        main.cpp
)

add_subdirectory(libfort)

target_link_libraries(CPP-project PRIVATE fort)