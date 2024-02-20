add_library(WRequests WRequests.hpp WRequests.cpp)

target_link_libraries(WRequests PUBLIC cpr::cpr)
target_link_libraries(WRequests PUBLIC nlohmann_json::nlohmann_json)
