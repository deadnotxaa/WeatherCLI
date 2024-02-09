#include <iostream>
// #include <cstdint>
#include <filesystem>
#include <string>

// #include <windows.h>
// #include <cpr/cpr.h>

// #include <nlohmann/json.hpp>
// #define json nlohmann::json

#include "lib/WConfig/WConfig.hpp"
#include "lib/WeatherInterface/WeatherInterface.hpp"


int main(int argc, char** argv) {
    WeatherUI::PrintWelcomeScreen();

    Weather weather;
    // weather.SetConfig();
    weather.CreateNewConfig();
    // std::string config_path;
    //
    // if (!std::filesystem::exists("config.json")) {
    //     std::cout << "Input path to config.json file" << std::endl;
    // } else {
    //     config_path = "\\config.json";
    // }
    //
    // WeatherUI ui(config_path);


    return 0;
}
