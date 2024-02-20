add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE WInterface)
target_link_libraries(${PROJECT_NAME} PRIVATE WConfig)
target_link_libraries(${PROJECT_NAME} PRIVATE WRequests)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
