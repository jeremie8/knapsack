cmake_minimum_required(VERSION 3.15)
project(Solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(Solver main.cpp cpp/item.cpp header/item.h cpp/greedy.cpp header/greedy.h cpp/input.cpp header/input.h cpp/output.cpp header/output.h cpp/dp.cpp header/dp.h cpp/branching.cpp header/branching.h)