#include"w_month.h"

class year
{
private:
    static const int MONTHS_IN_YEAR = 12;
    vector<month> months;
public:

    year() : months(MONTHS_IN_YEAR) {}

    month& getMonth(int month);
};
