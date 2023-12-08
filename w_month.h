#include"w_day.h"
#include<vector>
using namespace std;

class month
{
private:
   static const int DAYS_IN_MONTH = 31;
   vector<day> days;
public:

    month() : days(DAYS_IN_MONTH) {}
    day& getDay(int day);
    ~month();
};


