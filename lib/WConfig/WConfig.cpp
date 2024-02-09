#include "WConfig.hpp"

void Weather::SetConfig() {

    // Checks if config already exists and well-formated
    if (std::filesystem::exists(this->config_path)) {

        // Not well-formated
        if (CheckConfig(this->config_path) == false) {
            ErrorHandler(Errors::kWrongConfigFormat);
            CreateNewConfig();

            return;
        }

        ReadConfig(this->config_path);

        return;
    }

    std::cout << R"(Configuration file was not found automatically.)" << std::endl
              << R"(Do you already have config.json file? Type "YES" or "NO".)" << std::endl
              << R"(Another text would be interpreted as NO)" << std::endl;

    std::string input;
    std::cin >> input;

    if (input != "YES") {
        CreateNewConfig();

        return;
    }

    std::cout << "Type relative or absolute path to your config file" << std::endl;
    std::cin >> input;

    if (std::filesystem::exists(input) == false) {
        ErrorHandler(Errors::kFileDoesntExist);
        CreateNewConfig();

        return;
    }

    if (CheckConfig(input) == false) {
        ErrorHandler(Errors::kWrongConfigFormat);
        CreateNewConfig();

        return;
    }

    ReadConfig(input);
}

void Weather::ReadConfig(const std::string& config_path) {
    std::ifstream config_file(config_path);
    json config_data = json::parse(config_file);


}

bool Weather::CheckConfig(std::string&) {
    return false;
}

bool Weather::CreateNewConfig() {
    std::ofstream config_file("config.json", std::ios::out);
    json data = json::parse(R"({"cities": ["Stavropol", "Saint-Petersburg"]})");
    config_file << std::setw(4) << data << std::endl;
    return true;
}

void Weather::ErrorHandler(const Errors error) {
    switch (error) {
        case Errors::kWrongConfigFormat:
            std::cout << "Config is not supported or been corrupted" << std::endl;
            break;
        case Errors::kFileDoesntExist:
            std::cout << "File does not exist or wrong path was inputted" << std::endl;
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

