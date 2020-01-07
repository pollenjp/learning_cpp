cmake_minimum_required(VERSION 3.15)

set(This "example_test")

set(Sources
    example_test.cpp
)

add_executable(
    #[[<name>=]] ${This}
    #[[source...=]] ${Sources}
)

target_link_libraries(
    #[[<target> ... =]] ${This}
    PUBLIC
    #[[<item>...=]]
    gtest_main
    example
)


add_test(
    NAME example_test
    COMMAND example_test
)
