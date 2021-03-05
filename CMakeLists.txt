cmake_minimum_required(VERSION 3.17)
project(stockMarketSim)

set(CMAKE_CXX_STANDARD 14)

add_executable(stockMarketSim
        src/Bond.cpp src/Bond.h
        src/Instruments.cpp        src/Instruments.h
        src/Stock.cpp src/Stock.h
        src/stockMarketSim.cpp
        src/Market.h src/Market.cpp
        src/Player.cpp src/Player.h

        )