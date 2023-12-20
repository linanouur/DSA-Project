#include"w_year.h"
using namespace std;


class weatherHashTable {
private:
    std::vector<year> years;
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
                    std::cout<< "Date: " << w.getDate()[2] << "-" << w.getDate()[1] << "-" << w.getDate()[0] << std::endl;
                    std::cout<< "Max Temp: " << w.getMaxTemperature() << "°C, ";
                    std::cout<< "Min Temp: " << w.getMinTemperature() << "°C, ";
                    std::cout<< "Sunny Hours: " << w.getSunnyHours() << " hours, ";
                    std::cout<< "Condition: " << w.getCondition() << std::endl;
                    std::cout<< "----------------------------------------" << std::endl;
                
            
      }  
   



};