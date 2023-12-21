#include"weather.h"


class w_day
{

public:

    weather w;
    w_day();
    ~w_day();
    //void set w_dayWeather(const weather& we);
    w_day& operator=(const w_day& other) {
        if (this != &other) {
            w = other.w;  // Deep copy, provided weather has operator= implemented
        }
        return *this;
    }

};


