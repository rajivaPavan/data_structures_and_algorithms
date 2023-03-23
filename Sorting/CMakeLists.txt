cmake_minimum_required(VERSION 3.22)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES
        main.cpp
        sort.cpp
        sorting_handler.cpp
)

set(HEADERS
        sort.h
        sorting_handler.h
)
add_executable(Sorting ${SOURCES} ${HEADERS})
