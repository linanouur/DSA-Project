#include"w_month.h"


w_day& w_month::getDay(int day) {
        return days[day - 1];
    }

w_month::~w_month(){}