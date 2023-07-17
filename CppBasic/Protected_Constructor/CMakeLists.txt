cmake_minimum_required(VERSION 3.10)
project(Protected_constructor)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-g)
endif()

add_executable(Protected_constructor Protected_cons.cpp)
