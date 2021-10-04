cmake_minimum_required(VERSION 3.20)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp random.h airplane.h airplane.cpp train.h train.cpp ship.h ship.cpp container.cpp container.h transport.cpp transport.h)
