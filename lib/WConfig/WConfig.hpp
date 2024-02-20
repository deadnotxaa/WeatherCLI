#pragma once

#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>
#define json nlohmann::json

#include "../WRequests/WRequests.hpp"

namespace wwidget {

    struct CityData {
        CityData(std::string, double, double);
        CityData() = default;

        std::string city_name_{};
        double latitude_{};
        double longitude_{};
    };

    void to_json(json&, const CityData&);
    void from_json(const json&, CityData&);

    class Configuration {
        friend Requests;
    public:
        Configuration() = default;

        bool CreateConfigFile() noexcept;
        static bool IsConfigGood() noexcept;
        bool ReadConfigData() noexcept;

        void AddCities();
        void ChangeFrequency();
        void ChangeDaysNumber();

        static void CreateWeatherConfig() noexcept;
        static bool IsWeatherDataGood() noexcept;

        [[nodiscard]] uint32_t GetNumberOfDays() const;

    private:
        std::vector<CityData> cities_{};

        uint32_t frequency_{};
        uint32_t days_number_{};
    };

    static const char* config_file_name_ = "config.json";
    static const char* weather_config_name_ = "weather.json";

    static const char* cities_json_name_ = "cities";
    static const char* frequency_json_name_ = "frequency";
    static const char* days_number_json_name_ = "number_of_days";

    constexpr uint32_t kMinDaysNumber = 3;
    constexpr uint32_t kMinFrequency = 60;

} // namespace wwidget
