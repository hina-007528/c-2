#include <iostream>
#include <string>
using namespace std;
const int MAX_RECORDS = 100;  


struct WeatherData {
   string date;      
    double temperature;   
    double humidity;       
    double windSpeed;     
};


WeatherData weatherRecords[MAX_RECORDS];
int numRecords = 0;  

void logWeatherData(const string& date, double temperature, double humidity, double windSpeed) {
    if (numRecords >= MAX_RECORDS) {
       cout << "Error: Weather records are full." << endl;
        return;
    }

    weatherRecords[numRecords] = {date, temperature, humidity, windSpeed};
    ++numRecords;
}


void displayWeatherDataForDate(const string& date) {
    bool found = false;
    for (int i = 0; i < numRecords; ++i) {
        if (weatherRecords[i].date == date) {
           cout << "Date: " << weatherRecords[i].date << endl;
           cout << "Temperature: " << weatherRecords[i].temperature << " °C" << endl;
            cout << "Humidity: " << weatherRecords[i].humidity << " %" << endl;
            cout << "Wind Speed: " << weatherRecords[i].windSpeed << " km/h" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
       cout << "No weather data found for the date: " << date << endl;
    }
}

void calculateAverageTemperature(const string& startDate, const string& endDate) {
    double totalTemp = 0.0;
    int count = 0;

    for (int i = 0; i < numRecords; ++i) {
        if (weatherRecords[i].date >= startDate && weatherRecords[i].date <= endDate) {
            totalTemp += weatherRecords[i].temperature;
            ++count;
        }
    }

    if (count > 0) {
        double averageTemp = totalTemp / count;
       cout << "Average temperature from " << startDate << " to " << endDate << " is " << averageTemp << " °C" << endl;
    } else {
        cout << "No weather data available in the specified period." << endl;
    }
}


void findDayWithHighestWindSpeed() {
    if (numRecords == 0) {
        cout << "No weather data available." << endl;
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < numRecords; ++i) {
        if (weatherRecords[i].windSpeed > weatherRecords[maxIndex].windSpeed) {
            maxIndex = i;
        }
    }

   cout << "Day with the highest wind speed:" << endl;
   cout << "Date: " << weatherRecords[maxIndex].date << endl;
   cout << "Temperature: " << weatherRecords[maxIndex].temperature << " °C" << endl;
    cout << "Humidity: " << weatherRecords[maxIndex].humidity << " %" << endl;
    cout << "Wind Speed: " << weatherRecords[maxIndex].windSpeed << " km/h" << endl;
}

int main() {
   
    logWeatherData("2024-07-30", 32.5, 60.0, 15.0);
    logWeatherData("2024-07-31", 30.2, 65.0, 20.0);
    logWeatherData("2024-08-01", 29.8, 70.0, 18.0);
    logWeatherData("2024-08-02", 31.0, 55.0, 25.0);

  cout << "Weather data for 2024-08-01:" << endl;
    displayWeatherDataForDate("2024-08-01");

  
    cout << "\n";
    calculateAverageTemperature("2024-07-30", "2024-08-01");

    cout << "\n";
    findDayWithHighestWindSpeed();

    return 0;
}