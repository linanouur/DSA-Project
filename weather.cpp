
#include"weather.h"
using namespace std;



 // Constructors

    weather::weather()
    {
        for (int i = 0; i < 3; ++i) {
            date[i] = 0; // Copying each element
        }
         maxTemp=0;
         minTemp=0;
         condition="default";
         sunnyHours=0;

    }
   weather::weather(int *d,double max,double min, double sh,const string c)
        :  maxTemp(max), minTemp(min), condition(c), sunnyHours(sh) {
           
           
            for (int i = 0; i < 3; ++i) {
            date[i] = d[i]; // Copying each element
        }
        }


// Setters 
    void weather::setDate(const int*newDate) {
        date[0] = newDate[0];
        date[1] = newDate[1];
        date[2] = newDate[2];
    }

    void weather::setMaxTemperature(double temp) {
        maxTemp = temp;
    }

    void weather::setMinTemperature(double temp) {
        minTemp = temp;
    }

    void weather::setCondition(const std::string& cond) {
        condition = cond;
    }

    void weather::setSunnyHours(int hours) {
        sunnyHours = hours;
    }



// Getters 
    const int* weather::getDate() const {
        return date;
    }

    double weather::getMaxTemperature() const {
        return maxTemp;
    }

    double weather::getMinTemperature() const {
        return minTemp;
    }

    std::string weather::getCondition() const {
        return condition;
    }

    int weather::getSunnyHours() const {
        return sunnyHours;
    }

    
    weather::~weather(){}