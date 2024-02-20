#include "WInterface.hpp"

void wwidget::Interface::ShowWeather(uint32_t number_of_days) {
    using namespace ftxui;

    std::ifstream weather_data("weather.json", std::ios::in);
    json weather_json = json::parse(weather_data);

    std::ifstream config_data("config.json", std::ios::in);
    json config_json = json::parse(config_data);

    int32_t city_number = 0;
    std::size_t number_of_cities = config_json["cities"].size();

    std::vector<std::string> cities;
    for (int i = 0; i < number_of_cities; ++i) {
        cities.push_back(config_json["cities"][i]["city"]);
    }

    Elements elements;
    auto component = Renderer([&] {
        elements.clear();

        elements.emplace_back(text(cities[city_number]) | center);
        elements.push_back(separator());
        
        for (int i = 0; i < number_of_days; ++i) {
            // elements.push_back(text("\n"));

            elements.push_back(text(" " + to_string(weather_json[city_number]["hourly"]["time"][i * 24 + 8]).substr(1, 10) + " ") | center);

            elements.emplace_back(
                hbox({
                    window(
                        text(" Morning ") | center,
                        
                        hbox({
                            vbox({
                                text(weather_codes[weather_json[city_number]["hourly"]["weather_code"][i * 24 + 8]]) | center,
                            }) | center,

                            separator(),

                            vbox({
                                text(" temp: " + to_string(weather_json[city_number]["hourly"]["temperature_2m"][i * 24 + 8]) + "°C") | align_right,
                                text(" apparent temp: " + to_string(weather_json[city_number]["hourly"]["apparent_temperature"][i * 24 + 8]) +  + "°C") | align_right,
                                text(" humidity: " + to_string(weather_json[city_number]["hourly"]["relative_humidity_2m"][i * 24 + 8]) + "%") | align_right,
                                text(" wind speed: " + to_string(weather_json[city_number]["hourly"]["wind_speed_10m"][i * 24 + 8]) + "km/h") | align_right,
                            })
                        })
                    ) | flex,

                    window(
                        text(" Day ") | center,

                        hbox({
                            vbox({
                                text(weather_codes[weather_json[city_number]["hourly"]["weather_code"][i * 24 + 14]]) | center,
                            }) | center,

                            separator(),

                            vbox({
                                text(" temp: " + to_string(weather_json[city_number]["hourly"]["temperature_2m"][i * 24 + 14]) + "°C") | align_right,
                                text(" apparent temp: " + to_string(weather_json[city_number]["hourly"]["apparent_temperature"][i * 24 + 14]) +  + "°C") | align_right,
                                text(" humidity: " + to_string(weather_json[city_number]["hourly"]["relative_humidity_2m"][i * 24 + 14]) + "%") | align_right,
                                text(" wind speed: " + to_string(weather_json[city_number]["hourly"]["wind_speed_10m"][i * 24 + 14]) + "km/h") | align_right,
                            })
                        })
                    ) | flex,

                    window(
                        text(" Evening ") | center,

                        hbox({
                            vbox({
                                text(weather_codes[weather_json[city_number]["hourly"]["weather_code"][i * 24 + 18]]) | center,
                            }) | center,

                            separator(),

                            vbox({
                                text(" temp: " + to_string(weather_json[city_number]["hourly"]["temperature_2m"][i * 24 + 18]) + "°C") | align_right,
                                text(" apparent temp: " + to_string(weather_json[city_number]["hourly"]["apparent_temperature"][i * 24 + 18]) +  + "°C") | align_right,
                                text(" humidity: " + to_string(weather_json[city_number]["hourly"]["relative_humidity_2m"][i * 24 + 18]) + "%") | align_right,
                                text(" wind speed: " + to_string(weather_json[city_number]["hourly"]["wind_speed_10m"][i * 24 + 18]) + "km/h") | align_right,
                            })
                        })
                    ) | flex,

                    window(
                        text(" Night ") | center,

                        hbox({
                            vbox({
                                text(weather_codes[weather_json[city_number]["hourly"]["weather_code"][i * 24 + 23]]) | center,
                            }) | center,

                            separator(),

                            vbox({
                                text(" temp: " + to_string(weather_json[city_number]["hourly"]["temperature_2m"][i * 24 + 23]) + "°C") | align_right,
                                text(" apparent temp: " + to_string(weather_json[city_number]["hourly"]["apparent_temperature"][i * 24 + 23]) +  + "°C") | align_right,
                                text(" humidity: " + to_string(weather_json[city_number]["hourly"]["relative_humidity_2m"][i * 24 + 23]) + "%") | align_right,
                                text(" wind speed: " + to_string(weather_json[city_number]["hourly"]["wind_speed_10m"][i * 24 + 23]) + "km/h") | align_right,
                            })
                        })
                    ) | flex,
                })
            );
            elements.emplace_back(text("\n"));
        }

        return vbox(elements);
    });

    auto screen = ScreenInteractive::TerminalOutput();

    component |= CatchEvent([&](const Event& event) {
        if (event.character() == "n") {
            city_number < number_of_cities - 1 ? ++city_number : city_number = 0;
        } else if (event.character() == "p") {
            city_number > 0 ? --city_number : city_number = number_of_cities - 1;
        } else if (event.character() == "=") {
            number_of_days < 16 ? ++number_of_days : number_of_days = 16;
        } else if (event.character() == "-") {
            number_of_days > 1 ? --number_of_days : number_of_days = 1;
        } else if (event == Event::Escape) {

        }

        return 1;
    });

    screen.Loop(component);
}

void wwidget::Interface::PushBackOneWindow(const char* name, uint32_t index, ftxui::Elements elements) {

}
