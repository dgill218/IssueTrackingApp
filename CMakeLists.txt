cmake_minimum_required(VERSION 3.21)
project(IssueTrackingApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IssueTrackingApp
        main.cpp
        Project.cpp
        Project.h
        System.cpp
        System.h)
