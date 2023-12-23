#ifndef W_YEAR_H
#define W_YEAR_H

#include"w_month.h"

class w_year
{
private:
    
    vector<w_month> months;
public:
    static const int MONTHS_IN_YEAR = 12;
    w_year() : months(MONTHS_IN_YEAR) {}

    w_month& getMonth(int month);

    w_year& operator=(const w_year& other) {
        if (this != &other) {
            months = other.months;  // Deep copy, provided month has operator= implemented
        }
        return *this;
    }

    
};


#endif