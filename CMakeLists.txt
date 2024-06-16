cmake_minimum_required(VERSION 3.20.0)

project(
  feature
  VERSION 1.0.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(exec main.cpp)
