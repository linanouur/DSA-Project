#include"month.h"


day& month::getDay(int day) {
        return days[day - 1];
    }

month::~month(){}