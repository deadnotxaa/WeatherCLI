#pragma once

#include <string>
#include <format>
#include <iostream>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#define json nlohmann::json

namespace wwidget {

    class Requests {
    public:
        static bool IsCityExists(std::string&) noexcept;
        static void RefreshWeatherData() noexcept;

        static void GetWeatherData(std::string&);
        static void GetCityCoordinates(const std::string&, double&, double&);
    };

    static const char* api_ninjas_url_ = "https://api.api-ninjas.com/v1/city?name=";
    static const char* api_open_meteo_url_ = "https://api.open-meteo.com/v1/forecast?";

    // https://api.open-meteo.com/v1/forecast?latitude=59.94&longitude=30.31&hourly=temperature_2m&forecast_days=16

} // namespace wwidget
