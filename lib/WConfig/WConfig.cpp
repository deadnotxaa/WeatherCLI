#include "WConfig.hpp"

void Weather::SetConfig() {
    initscr();

    // Checks if config already exists and well-formated
    if (std::filesystem::exists(this->config_path)) {

        // Not well-formated
        if (CheckConfig() == false) {
            ErrorHandler(Errors::kWrongConfigFormat);
            CreateNewConfig();

            return;
        }
        ReadConfig();

        return;
    }
    printw("Configuration file was not found automatically.\n");

    CreateNewConfig();
    ReadConfig();

    getch();
    endwin();
}

void Weather::ReadConfig() {
    std::ifstream config_file(config_path);

    json config_data = json::parse(config_file);

    this->cities = config_data["cities"];
    this->frequency = config_data["frequency"];
    this->number_of_days = config_data["number_of_days"];
}

bool Weather::CheckConfig() const {
    std::ifstream config_file(this->config_path, std::ios::in);

    json config_data = json::parse(config_file);

    if (config_data.contains("cities") &&
        config_data.contains("frequency") &&
        config_data.contains("number_of_days"))
    {
        return true;
    }

    return false;
}

void Weather::CreateNewConfig() {
    std::ofstream config_file("config.json", std::ios::out);

    json config_data = json::parse(R"({"cities": ["Stavropol", "Saint-Petersburg"], "frequency": 60, "number_of_days": 3})");
    config_file << std::setw(4) << config_data << std::endl;

    config_file.close();
}

void Weather::ErrorHandler(const Errors error) {
    switch (error) {
        case Errors::kWrongConfigFormat:
            std::cout << "Config is not supported or been corrupted" << std::endl;
            break;
        case Errors::kConfigCreationError:
            std::cout << "Config file was not created because of unexpected problem."
                         "Restart the programm and try again" << std::endl;
            exit(EXIT_FAILURE);
        default:
            std::cout << "Unexpected error occured" << std::endl;
            exit(EXIT_FAILURE);
    }
}

void Weather::PrintWelcomeMessage() {
    // Initiating a screen
    initscr();
    noecho();

    // Setting color for text
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    printw("\n\n");

    attron(COLOR_PAIR(1));
    printw(
                " /$$      /$$                       /$$     /$$                          \n" \
                "| $$  /$ | $$                      | $$    | $$                          \n" \
                "| $$ /$$$| $$  /$$$$$$   /$$$$$$  /$$$$$$  | $$$$$$$   /$$$$$$   /$$$$$$ \n" \
                "| $$/$$ $$ $$ /$$__  $$ |____  $$|_  $$_/  | $$__  $$ /$$__  $$ /$$__  $$\n" \
                "| $$$$_  $$$$| $$$$$$$$  /$$$$$$$  | $$    | $$  \\ $$| $$$$$$$$| $$  \\__/\n" \
                "| $$$/ \\  $$$| $$_____/ /$$__  $$  | $$ /$$| $$  | $$| $$_____/| $$      \n" \
                "| $$/   \\  $$|  $$$$$$$|  $$$$$$$  |  $$$$/| $$  | $$|  $$$$$$$| $$      \n" \
                "|__/     \\__/ \\_______/ \\_______/   \\___/  |__/  |__/ \\_______/|__/      \n" \
    );
    printw("\n\n");

    attron(COLOR_PAIR(2));
    printw("This utility is designed to show weather using you CLI interface.\n\n");
    printw("\tTo change between cities simply press n (next) and p (previous) on your keyboard\n");
    printw("\tTo change number of days forecast press + (more) or - (less)\n");
    printw("\tTo exit the programm press Esc\n\n");
    printw("Now you will be able to configure number of days, update frequency and list of cities to show in your forecast\n\n");
    printw("Press any key to continue!\n");

    getch();
    endwin();
}

