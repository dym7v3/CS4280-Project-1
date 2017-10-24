cmake_minimum_required(VERSION 3.8)
project(P1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp scanner.cpp scanner.h token.h filterFunction.cpp filterFunction.h token.cpp FileInputFunction.cpp  FileInputFunction.h)
add_executable(P1 ${SOURCE_FILES} )