#include"w_year.h"



w_month& w_year::getMonth(int month) {
        return months[month - 1]; 
    }

