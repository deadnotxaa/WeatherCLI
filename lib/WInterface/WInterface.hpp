#pragma once

#include <iostream>
#include <cstdint>
#include <string>

#include <ncurses.h>

class WeatherUI {
public:
    WeatherUI() = default;
    explicit WeatherUI(std::string&);

    static void PrintWelcomeScreen();
    void ShowWeatherInterface();

private:

    struct KeyCodes {
        static constexpr int kEscKey = 27;
        static constexpr int kLowerPKey = 112;
        static constexpr int kLowerNKey = 110;
        static constexpr int kPlusKey = 43;
        static constexpr int kMinusKey = 45;

    };

};
