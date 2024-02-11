#include <iostream>
// #include <cstdint>
#include <filesystem>
#include <string>

#include "lib/WConfig/WConfig.hpp"
// #include "lib/WInterface/WInterface.hpp"


int main(int argc, char** argv) {
    Weather::PrintWelcomeMessage();

    Weather weather;
    weather.SetConfig();

    return 0;
}
