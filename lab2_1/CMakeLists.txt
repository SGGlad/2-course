cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME lab2_1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable("${PROJECT_NAME}"  "envariant.cpp")
