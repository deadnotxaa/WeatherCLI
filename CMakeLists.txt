cmake_minimum_required(VERSION 3.12)

project(
        weather_forecast
        VERSION 1.0
        DESCRIPTION "C++ Console Weather Forecast"
        LANGUAGES CXX
)

include(FetchContent)

# CPR
FetchContent_Declare(cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

# JSON
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

set(GCC_COVERAGE_COMPILE_FLAGS "-lncurses")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# NCURSES
#FetchContent_Declare(ncurses
#        GIT_REPOSITORY https://github.com/mirror/ncurses
#        GIT_TAG v6.4
#)
#FetchContent_MakeAvailable(ncurses)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(bin)
