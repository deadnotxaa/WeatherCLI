add_library(WConfig WConfig.hpp WConfig.cpp)

target_link_libraries(WConfig PUBLIC cpr::cpr)
target_link_libraries(WConfig PUBLIC nlohmann_json::nlohmann_json)
