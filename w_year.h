#include"w_month.h"

class year
{
private:
    
    vector<month> months;
public:
    static const int MONTHS_IN_YEAR = 12;
    year() : months(MONTHS_IN_YEAR) {}

    month& getMonth(int month);

    year& operator=(const year& other) {
        if (this != &other) {
            months = other.months;  // Deep copy, provided month has operator= implemented
        }
        return *this;
    }

    month& getMonth(int monthIndex) {
        if (monthIndex >= 0 && monthIndex < MONTHS_IN_YEAR) {
            return months[monthIndex];
        } else {
            throw std::out_of_range("Invalid month index");
        }
    }
};
