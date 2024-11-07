cmake_minimum_required(VERSION 3.26.0)
project(strava__)

set(CMAKE_CXX_STANDARD 20)

if ((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") AND NOT (MINGW)))

    message(STATUS "Your compiler is ${CMAKE_CXX_COMPILER_ID}!")

    # should be using GCC or CLANG

    # Both, GCC and Clang support the same option set
    # We first turn on Warnings
    # --> https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
    #
    # -Wall stands for All Warnings
    # -Wextra pushes that a bit further
    # -pedantic sets the compiler to use strict ISO C++
    # -Werror treats all warnings as errors so you have to fix them
    #   add_compile_options(-Wall -Wextra -pedantic) # -Werror)
    #
    # Sanitizer options
    # The following will turn on Debugging (-g flag) and the Address Sanitizer
    # which is turned on with the -fsanitize=address option to the compiler.
    add_compile_options(-Wall -Wextra -pedantic -fsanitize=address,undefined -g)

    # When we turn on the sanitizer, you also need to instruct the
    # linker that it will be used which happens with the following
    # link option command.
    add_link_options(-fsanitize=address,undefined -g)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    # MSVC uses a different warning flags
    add_compile_options(/W4)  # shut off warnings as errors, which is the /Wx option
    add_compile_options(/fsanitize=address)

endif()

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(strava__ main.cpp
        Activity.cpp
        Activity.h
)
