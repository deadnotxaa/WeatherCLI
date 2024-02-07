add_executable(${PROJECT_NAME} main.cpp)

# CPR
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)
target_link_libraries(${PROJECT_NAME} PRIVATE weather)
target_link_libraries(${PROJECT_NAME} PRIVATE weatherUI)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
