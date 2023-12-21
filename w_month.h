#include"w_day.h"
#include<vector>
using namespace std;

class month
{
private:
   
   vector<day> days;
public:
    static const int DAYS_IN_MONTH = 31;
    month() : days(DAYS_IN_MONTH) {}
    day& getDay(int day);

    month& operator=(const month& other) {
        if (this != &other) {
            days = other.days;  // Deep copy, provided day has operator= implemented
        }
        return *this;
    }

    
    ~month();
};


