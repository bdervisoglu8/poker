cmake_minimum_required(VERSION 4.0)
project(Poker_Recovered)

set(CMAKE_CXX_STANDARD 20)

add_executable(Poker_Recovered main.cpp
        Functions.h
        Poker_Types.h
        Primitives.h
        Probability.h
        Functioms.cpp
        Primitives.cpp
        Probability.cpp)
