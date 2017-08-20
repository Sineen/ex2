cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES
        MyString.c
        MyString.h
        LineSeparator.c
        LineSeparator.h)

add_executable(ex2 ${SOURCE_FILES})