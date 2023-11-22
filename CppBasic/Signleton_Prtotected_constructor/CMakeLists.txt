cmake_minimum_required(VERSION 3.10)
project(Singleton_T_Class_Protected_Constructor_example)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
   add_compile_options(-g)
endif()
  
add_executable(Singleton_T_Class_Protected_Constructor_example Singleton.cpp)

