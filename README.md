# Weather Widget

Weather Widget (wwidget) is a C++ console application that provides weather forecasts for multiple cities. The application fetches weather data from the internet and displays it in a user-friendly format using the FTXUI library.

## Features

- Fetches weather data for multiple cities.
- Displays weather data for up to 16 days.
- User-friendly console interface using FTXUI.
- Configurable refresh frequency and number of forecast days.
- Easily add or remove cities.

## Installation

### Prerequisites
- CMake 3.28 or higher
- C++20 or higher

## Usage
When you run the application, it will first check if the configuration files (```config.json``` and ```weather.json```) exist. If they do not exist or are invalid, the application will prompt you to create them by providing necessary information such as city names, refresh frequency, and number of forecast days.

**Example:**  
<img width="1719" alt="image" src="https://github.com/deadnotxaa/WeatherCLI/assets/91655231/4271d54c-1a6d-4d79-88aa-20b171dd8b81">


## Displaying Weather Forecast
The weather forecast will be displayed in the console using the FTXUI library. Use the following controls:

* ```n```: Next city.
* ```p```: Previous city.
* ```=```: Increase the number of forecast days.
* ```-```: Decrease the number of forecast days.

## Code Structure

### Main Application (```main.cpp```)
The entry point of the application, initializes the configuration, checks and reads the configuration file, creates weather configuration if needed, and displays the weather using the Interface class.

```cpp
#include "lib/WConfig/WConfig.hpp"
#include "lib/WInterface/WInterface.hpp"
#include "lib/WRequests/WRequests.hpp"

int main(int argc, char** argv) {
    wwidget::Configuration configuration;

    if (wwidget::Configuration::IsConfigGood()) {
        configuration.ReadConfigData();
    } else {
        configuration.CreateConfigFile();
    }

    if (!wwidget::Configuration::IsWeatherDataGood()) {
        wwidget::Configuration::CreateWeatherConfig();
    }

    wwidget::Interface::ShowWeather(configuration.GetNumberOfDays());

    return 0;
}
```

### Configuration Management (WConfig)
Handles the creation, validation, and reading of the configuration file.

```WConfig.hpp```: Declares the Configuration class and related functions.
```WConfig.cpp```: Implements the Configuration class methods.

### User Interface (WInterface)
Displays the weather forecast using the FTXUI library.

```WInterface.hpp```: Declares the Interface class and related functions.
```WInterface.cpp```: Implements the Interface class methods.

### Weather Requests (WRequests)
Fetches weather data and city coordinates from external APIs.

```WRequests.hpp```: Declares the Requests class and related functions.
```WRequests.cpp```: Implements the Requests class methods.

## Dependencies
**CMake**
The project uses CMake for build configuration. The CMakeLists.txt files define the build settings and dependencies.

**Libraries**
CPR: For making HTTP requests.
JSON for Modern C++: For parsing JSON data.
FTXUI: For building the console user interface.
