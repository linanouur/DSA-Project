#ifndef WEATHER_H
#define WEATHER_H
#include<iostream>
#include<string>

using namespace std;

class weather
{
private:
    int date[3]; //day_month_year
    double maxTemp;
    double minTemp;
    double sunnyHours;
    string condition; //sunny/cloudy/rainy/snowy
public:

//constructors
    weather();
    weather( int *d,double max,double min, double sh,const string c);


//setters
    void setDate(const int*newDate);
    void setMaxTemperature(double temp);
    void setMinTemperature(double temp);
    void setCondition(const std::string& cond);
    void setSunnyHours(int hours);

//getters
    const int* getDate() const;
    double getMaxTemperature() const;
    double getMinTemperature() const;
    std::string getCondition() const;
    int getSunnyHours() const;

    weather& operator=(const weather& other) {
        if (this != &other) {
            // Copy all data members
            maxTemp = other.maxTemp;
            minTemp = other.minTemp;
            sunnyHours = other.sunnyHours;
            condition = other.condition;
            std::copy(std::begin(other.date), std::end(other.date), std::begin(date));
        }
        return *this;
    }

    
    ~weather();
};

#endif