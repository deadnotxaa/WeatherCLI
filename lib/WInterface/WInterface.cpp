#include "WInterface.hpp"

WeatherUI::WeatherUI(std::string&) {

}

void WeatherUI::PrintWelcomeScreen() {

    std::cout << std::endl << std::endl;
    std::cout << \
                " /$$      /$$                       /$$     /$$                          \n" \
                "| $$  /$ | $$                      | $$    | $$                          \n" \
                "| $$ /$$$| $$  /$$$$$$   /$$$$$$  /$$$$$$  | $$$$$$$   /$$$$$$   /$$$$$$ \n" \
                "| $$/$$ $$ $$ /$$__  $$ |____  $$|_  $$_/  | $$__  $$ /$$__  $$ /$$__  $$\n" \
                "| $$$$_  $$$$| $$$$$$$$  /$$$$$$$  | $$    | $$  \\ $$| $$$$$$$$| $$  \\__/\n" \
                "| $$$/ \\  $$$| $$_____/ /$$__  $$  | $$ /$$| $$  | $$| $$_____/| $$      \n" \
                "| $$/   \\  $$|  $$$$$$$|  $$$$$$$  |  $$$$/| $$  | $$|  $$$$$$$| $$      \n" \
                "|__/     \\__/ \\_______/ \\_______/   \\___/  |__/  |__/ \\_______/|__/      \n" << std::endl;
}

void WeatherUI::ShowWeatherInterface() {
    initscr();
    int64_t pressed_key{};

    while (pressed_key != KeyCodes::kEscKey) {

        switch (pressed_key) {
            case KeyCodes::kLowerNKey:
                std::cout << "n" << std::endl;
                break;
            case KeyCodes::kLowerPKey:
                std::cout << "p" << std::endl;
                break;
            case KeyCodes::kPlusKey:
                std::cout << "+" << std::endl;
                break;
            case KeyCodes::kMinusKey:
                std::cout << "-" << std::endl;
                break;
            default:
                break;
        }

        pressed_key = getch();
    }
}
