#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>
#define json nlohmann::json

enum class Errors {
    kWrongConfigFormat,
    kFileDoesntExist,
    kConfigCreationError,
};

class Weather {
public:
    Weather() = default;

    void SetConfig();
    void ReadConfig(const std::string&);
    bool CheckConfig(std::string&);
    bool CreateNewConfig();

    static void ErrorHandler(Errors);

private:
    std::string config_path = "\\config.json";
    std::vector<std::string> cities;
};
