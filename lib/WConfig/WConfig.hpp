#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

#include <ncurses.h>
#include <nlohmann/json.hpp>

#define json nlohmann::json

enum class Errors {
    kWrongConfigFormat,
    kConfigCreationError,
};

class Weather {
public:
    Weather() = default;

    void SetConfig();
    void ReadConfig();
    bool CheckConfig() const;
    static void CreateNewConfig();

    static void ErrorHandler(Errors);
    static void PrintWelcomeMessage();

private:
    std::string config_path = "config.json";
    std::vector<std::string> cities;
    uint64_t frequency = 3;
    uint64_t number_of_days = 3;
};
