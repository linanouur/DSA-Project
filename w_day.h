#include"weather.h"


class day
{

public:

    weather w;
    day();
    ~day();
    //void setDayWeather(const weather& we);
    day& operator=(const day& other) {
        if (this != &other) {
            w = other.w;  // Deep copy, provided weather has operator= implemented
        }
        return *this;
    }

};


