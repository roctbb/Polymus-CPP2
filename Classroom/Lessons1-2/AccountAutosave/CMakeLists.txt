cmake_minimum_required(VERSION 3.6)
project(AccountAutosave)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Account.cpp Account.h)
add_executable(AccountAutosave ${SOURCE_FILES})