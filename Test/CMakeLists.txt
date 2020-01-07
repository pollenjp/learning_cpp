cmake_minimum_required(VERSION #[[<min>]] 3.15)

set(project_name "ExampleDemo")
project(#[[<PROJECT-NAME>=]] ${project_name}
        VERSION 0.1
        DESCRIPTION "Google Test Demonstration"
        HOMEPAGE_URL "https://www.example.com"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


add_subdirectory(src)


################################################################################
################################################################################
enable_testing()
add_subdirectory(test)
add_subdirectory(third_party/googletest)
################################################################################
################################################################################
#set(SOURCES
#    main.cpp
#)
#
#add_executable(main ${SOURCES})
#
#target_link_libraries(main example)
#
#
#message("Here is : ${PROJECT_BINARY_DIR}")
#message("Here is : ${CMAKE_CURRENT_BINARY_DIR}")