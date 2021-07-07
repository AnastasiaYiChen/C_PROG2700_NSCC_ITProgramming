cmake_minimum_required(VERSION 3.15)
project(FancyFunction C)

set(CMAKE_C_STANDARD 99)

add_executable(FancyFunction main.c bisect.c)

target_link_libraries(FancyFunction m)