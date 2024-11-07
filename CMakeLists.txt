cmake_minimum_required(VERSION 3.26.0)
project(strava__)

set(CMAKE_CXX_STANDARD 20)

add_executable(strava__ main.cpp
        Activity.cpp
        Activity.h
)
