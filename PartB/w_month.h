#ifndef W_MONTH_H
#define W_MONTH_H
#include"w_day.h"
#include<vector>
using namespace std;

class w_month
{
private:
   
   vector<w_day> days;
public:
    static const int DAYS_IN_MONTH = 31;
    w_month() : days(DAYS_IN_MONTH) {}
    w_day& getDay(int day);

    w_month& operator=(const w_month& other) {
        if (this != &other) {
            days = other.days;  // Deep copy, provided day has operator= implemented
        }
        return *this;
    }

    
    ~w_month();
};


#endif