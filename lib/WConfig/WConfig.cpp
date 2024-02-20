#include "WConfig.hpp"

wwidget::CityData::CityData(std::string city_name, const double latitude, const double longitude)
            : city_name_(std::move(city_name)), latitude_(latitude), longitude_(longitude)
{
}

void wwidget::to_json(json& j, const CityData& data) {
    j = json{{"city", data.city_name_}, {"latitude", data.latitude_}, {"longitude", data.longitude_}};
}

void wwidget::from_json(const json& j, CityData& data) {
    j.at("city").get_to(data.city_name_);
    j.at("latitude").get_to(data.latitude_);
    j.at("longitude").get_to(data.longitude_);
}

bool wwidget::Configuration::CreateConfigFile() noexcept {
    if (std::filesystem::exists(config_file_name_)) {
        std::filesystem::remove(config_file_name_);
        std::cout << "Old config file was deleted" << std::endl;
    }

    std::ofstream config_file(config_file_name_, std::ios::out);

    if (!config_file.good()) {
        return false;
    }

    json config_json;

    AddCities();
    ChangeFrequency();
    ChangeDaysNumber();

    config_json[cities_json_name_] = this->cities_;
    config_json[frequency_json_name_] = this->frequency_;
    config_json[days_number_json_name_] = this->days_number_;

    // write pretty-formatted json file
    config_file << std::setw(4) <<  config_json << std::endl;
    return true;
}

bool wwidget::Configuration::IsConfigGood() noexcept {
    if (std::filesystem::exists(config_file_name_) == false) {
       return false;
    }

    std::ifstream config_file(config_file_name_, std::ios::in);

    json config_data;

    try {
        config_data = json::parse(config_file);
    }
    catch (const json::parse_error& error) {
        std::cerr << "ERROR!!11!!!1!!11" << std::endl << error.what() << std::endl;
        return false;
    }

    if (!(config_data.contains(cities_json_name_) &&
        config_data.contains(frequency_json_name_) &&
        config_data.contains(days_number_json_name_)))
    {
        return false;
    }

    if (config_data[cities_json_name_].empty() ||
        config_data[frequency_json_name_] < kMinFrequency ||
        config_data[days_number_json_name_] < kMinDaysNumber)
    {
        return false;
    }

    return true;
}

bool wwidget::Configuration::ReadConfigData() noexcept {
    std::ifstream config_file(config_file_name_, std::ios::in);

    json config_data;

    try {
        config_data = json::parse(config_file);
    }
    catch (const json::parse_error& error) {
        std::cerr << "ERROR!!11!!!1!!11" << std::endl;
        return false;
    }

    for (int i = 0; i < config_data[cities_json_name_].size(); ++i) {
        CityData data = config_data[cities_json_name_][i].template get<wwidget::CityData>();

        this->cities_.push_back(data);
    }
    // this->cities_ = config_data[cities_json_name_];
    this->frequency_ = config_data[frequency_json_name_];
    this->days_number_ = config_data[days_number_json_name_];

    return true;
}

void wwidget::Configuration::AddCities() {
    std::cout << "Input number of cities to add (min = 1)" << std::endl;
    int32_t number_of_cities{};

    do {
        std::cin >> number_of_cities;

        if (number_of_cities < 1) {
            std::cerr << "ti daun?" << std::endl;
        }
    } while (number_of_cities < 1);

    std::string city_name;
    for (int i = 0; i < number_of_cities; ++i) {
        std::cout << "Input city #" << i + 1 << " name" << std::endl;
        std::cin >> city_name;
        std::cout << std::endl;

        if (Requests::IsCityExists(city_name) == false) {
            std::cerr << "City with such name doesn't exist" << std::endl;
            i--;
        }
        double latitude;
        double longitude;

        Requests::GetCityCoordinates(city_name, latitude, longitude);

        this->cities_.emplace_back(city_name, latitude, longitude);
    }
}

void wwidget::Configuration::ChangeFrequency() {
    std::cout << "Input refresh frequency (min=60, max=1440)" << std::endl;

    int32_t frequency{};

    do {
        std::cin >> frequency;
        if (frequency < 60 || frequency > 1440) {
            std::cerr << "ti daun?" << std::endl;
        }
    } while (frequency < 60 || frequency > 1440);

    this->frequency_ = frequency;
}

void wwidget::Configuration::ChangeDaysNumber() {
    std::cout << "Input number of days for forecast (min = 1, max=16)" << std::endl;
    int32_t days_number{};

    do {
        std::cin >> days_number;

        if (days_number < 1 || days_number > 16) {
            std::cerr << "ti daun?" << std::endl;
        }
    } while (days_number < 1 || days_number > 16);

    this->days_number_ = days_number;
}

void wwidget::Configuration::CreateWeatherConfig() noexcept {
    std::ofstream config(weather_config_name_, std::ios::out);

    std::string weather_data;
    Requests::GetWeatherData(weather_data);

    std::cout << weather_data << std::endl;

    json weather_json;

    try {
        weather_json = json::parse(weather_data);
    }
    catch (const json::parse_error& error) {
        std::cerr << "1ERROR!!11!!!1!!11" << std::endl;
        return;
    }

    config << std::setw(4) << weather_json << std::endl;
}

bool wwidget::Configuration::IsWeatherDataGood() noexcept {
    if (std::filesystem::exists(weather_config_name_) == false) {
        return false;
    }

    std::ifstream config(weather_config_name_, std::ios::in);

    json weather_data;

    try {
        weather_data = json::parse(config);
    }
    catch (const json::parse_error& error) {
        std::cerr << "2ERROR!!11!!!1!!11" << std::endl;
        return false;
    }

    return true;
}

uint32_t wwidget::Configuration::GetNumberOfDays() const {
    return this->days_number_;
}
