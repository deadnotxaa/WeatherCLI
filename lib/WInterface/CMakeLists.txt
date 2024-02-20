add_library(WInterface WInterface.hpp WInterface.cpp)

target_link_libraries(WInterface
        PUBLIC ftxui::screen
        PUBLIC ftxui::dom
        PUBLIC ftxui::component
)

target_link_libraries(WInterface PUBLIC nlohmann_json::nlohmann_json)
