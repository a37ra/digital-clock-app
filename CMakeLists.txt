cmake_minimum_required(VERSION 3.10)
project(DigitalClockApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clock main.cpp)

if(MSVC)
    target_compile_options(clock PRIVATE /W3)
else()
    target_compile_options(clock PRIVATE -Wall -O2)
endif()