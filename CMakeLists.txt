cmake_minimum_required(VERSION 3.3)
project(Projekt_SO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c Proces1.c Proces1.h)
add_executable(dbsg ${SOURCE_FILES})
