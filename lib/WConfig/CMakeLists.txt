add_library(WConfig WConfig.cpp WConfig.hpp)

target_link_libraries(WConfig PUBLIC cpr::cpr)
target_link_libraries(WConfig PUBLIC nlohmann_json::nlohmann_json)
