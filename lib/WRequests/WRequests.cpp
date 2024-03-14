#include "WRequests.hpp"

#include "../WConfig/WConfig.hpp"

bool wwidget::Requests::IsCityExists(std::string& city_name) noexcept {
    cpr::Response response = cpr::Get(cpr::Url{api_ninjas_url_ + city_name},
                             cpr::Header{{"X-Api-Key", ""}});

    if (response.text == "[]") {
        return false;
    }

    return true;
}

void wwidget::Requests::RefreshWeatherData() noexcept {

}

void wwidget::Requests::GetWeatherData(std::string& weather_responce) {
    std::stringstream format_request;

    std::ifstream config_json(config_file_name_, std::ios::in);

    json config_data = json::parse(config_json);
    std::size_t number_of_cities = config_data[cities_json_name_].size();

    format_request << "latitude=";
    for (int i = 0; i < number_of_cities; ++i) {
        if (i != number_of_cities - 1) {
            format_request << to_string(config_data[cities_json_name_][i]["latitude"]).substr(0, 5) << ",";
        }
        else {
            format_request << to_string(config_data[cities_json_name_][i]["latitude"]).substr(0, 5);
        }
    }

    format_request << "&longitude=";
    for (int i = 0; i < number_of_cities; ++i) {
        if (i != number_of_cities - 1) {
            format_request << to_string(config_data[cities_json_name_][i]["longitude"]).substr(0, 5) << ",";
        }
        else {
            format_request << to_string(config_data[cities_json_name_][i]["longitude"]).substr(0, 5);
        }
    }

    format_request << "&hourly=temperature_2m,relative_humidity_2m,apparent_temperature,precipitation,weather_code,wind_speed_10m,wind_direction_10m&forecast_days=16";

    std::cout << format_request.str() << std::endl;

    cpr::Response responce = cpr::Get(cpr::Url{api_open_meteo_url_ + format_request.str()});
    weather_responce = responce.text;
}

void wwidget::Requests::GetCityCoordinates(const std::string& city_name, double& latitude, double& longitude) {
    cpr::Response response = cpr::Get(cpr::Url{api_ninjas_url_ + city_name},
                             cpr::Header{{"X-Api-Key", ""}});

    json city_data;

    try {
        city_data = json::parse(response.text.substr(1, response.text.length() - 2));
    }
    catch (const json::parse_error& error) {
        return;
    }

    latitude = city_data["latitude"];
    longitude = city_data["longitude"];
}
