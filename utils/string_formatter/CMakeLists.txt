cmake_minimum_required(VERSION #[[<min>=]] 3.1)
project(#[[<PROJECT-NAME>=]] main #[[<language-name>=]] CXX)
set(CMAKE_CXX_STANDARD 20)
include_directories(#[[dir=]] include)

set(SOURCES main.cpp)
add_executable(#[[<name>=]] main
               #[[source=]] ${SOURCES})
