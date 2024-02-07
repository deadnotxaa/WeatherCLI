cmake_minimum_required(VERSION 3.12)

project(
        weather_forecast
        VERSION 1.0
        DESCRIPTION "C++ Console Weather Forecast"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_subdirectory(lib)
add_subdirectory(bin)
