cmake_minimum_required(VERSION 3.6)
project(CustomList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp core/ListIterator.cpp core/ListIterator.h core/List.cpp core/List.h core/Node.cpp core/Node.h)
add_executable(CustomList ${SOURCE_FILES})