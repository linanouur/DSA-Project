#include"w_year.h"
#include <fstream>
#include <sstream>
using namespace std;


class weatherHashTable {
private:
    std::vector<w_year> years;
    int startYear; 

public:
    weatherHashTable();
    weatherHashTable(int startYear,int numberOfYears );

    void addYear(int year);

    weather& getWeather(int year, int month, int day);

    void insertWeather(int year, int month, int day, const weather& weather) ;

    int getsize(){return years.size();}


    weatherHashTable& operator=(const weatherHashTable& other) {
        if (this != &other) { // Check for self-assignment
            this->startYear = other.startYear;
            this->years = other.years;  // Assuming 'year' supports copying
        }
        return *this;
    }

    void printWeatherInfo(int y,int m,int d) const {
        weatherHashTable wht;
        weather w=wht.getWeather(y,m,d);
        

                    //  date[0] = day, date[1] = month, date[2] = year
                    std::cout<< "\t\t\t ----------------------------------------" << std::endl;
                    std::cout<< "\t\t\t\t Date: " << w.getDate()[2] << "-" << w.getDate()[1] << "-" << w.getDate()[0] << std::endl;
                    std::cout<< "\t\t\t\t Max Temp: " << w.getMaxTemperature() << "°C, "<<endl;
                    std::cout<< "\t\t\t\t Min Temp: " << w.getMinTemperature() << "°C, "<<endl;
                    std::cout<< "\t\t\t\t Sunny Hours: " << w.getSunnyHours() << " hours, "<<endl;
                    std::cout<< "\t\t\t\t Condition: " << w.getCondition() << std::endl;
                    std::cout<< "\t\t\t ----------------------------------------" << std::endl;
                
            
      }  



       void readWeatherFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        // Skip the header line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string dateStr, maxTempStr, minTempStr, sunnyHoursStr, condition;
            int date[3], day, month, year;
            double maxTemp, minTemp;
            int sunnyHours;

            std::getline(ss, dateStr, ',');
            std::getline(ss, maxTempStr, ',');
            std::getline(ss, minTempStr, ',');
            std::getline(ss, sunnyHoursStr, ',');
            std::getline(ss, condition);

            // Parse date
            std::stringstream dateSS(dateStr);
            std::string token;
            std::getline(dateSS, token, '-');
            day = std::stoi(token);
            std::getline(dateSS, token, '-');
            month = std::stoi(token);
            std::getline(dateSS, token, '-');
            year = std::stoi(token);

            // Set date array
            date[0] = day;
            date[1] = month;
            date[2] = year;

            // Parse other data
            maxTemp = std::stod(maxTempStr);
            minTemp = std::stod(minTempStr);
            sunnyHours = std::stoi(sunnyHoursStr);

            // Create a weather object and insert it into the hash table
            weather w(date, maxTemp, minTemp, sunnyHours, condition);
            insertWeather(year, month, day, w);
        }
    }
};

   
