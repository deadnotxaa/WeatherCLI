#pragma once

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <fstream>
#include <map>

#include <nlohmann/json.hpp>
#define json nlohmann::json

namespace wwidget {

    class Interface {
    public:
        static void ShowWeather(uint32_t);

        void PushBackOneWindow(const char*, uint32_t, ftxui::Elements);
    };

    inline std::map<int, std::string> weather_codes{
        {0, "Clear sky"},
        {1, "Mainly clear"},
        {2, "Partly cloudy"},
        {3, "Overcast"},
        {45, "Fog"},
        {48, "Depositing rime fog"},
        {51, "Light dizzle"},
        {53, "Moderate dizzle"},
        {55, "Dense intensity dizzle"},
        {56, "Light freezing drizzle"},
        {57, "Dense intensity freezing drizzle"},
        {61, "Slight rain"},
        {63, "Moderate rain"},
        {65, "Dense intensity rain"},
        {66, "Light freezing rain"},
        {67, "Heavy intensity freezing rain"},
        {71, "Slight snow fall"},
        {73, "Moderate snow fall"},
        {75, "Heavy intensity snow fall"},
        {77, "Snow grains"},
        {80, "Slight rain showers"},
        {81, "Moderate rain showers"},
        {82, "Violent rain showers"},
        {85, "Slight snow showers"},
        {86, "Heavy snow showers"}
    };

} // namespace wwidget
