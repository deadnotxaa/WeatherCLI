#include <thread>

#include "lib/WConfig/WConfig.hpp"
#include "lib/WInterface/WInterface.hpp"
#include "lib/WRequests/WRequests.hpp"

int main(int argc, char** argv)
{
    wwidget::Configuration configuration;

    if (wwidget::Configuration::IsConfigGood()) {
        configuration.ReadConfigData();
    } else {
        configuration.CreateConfigFile();
    }

    if (wwidget::Configuration::IsWeatherDataGood() == false) {
        wwidget::Configuration::CreateWeatherConfig();
    }

    wwidget::Interface::ShowWeather(configuration.GetNumberOfDays());

    return 0;
}
