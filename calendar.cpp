#ifndef CALENDAR_H 
#define CALENDAR_H
 #include <iostream>
#include <string>
#include"bills.cpp"

using namespace std;


class Months
{
public:
    Bill months[13];
    Months()
    {
        const string monthNames[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"};

        for (int i = 1; i <= 12; ++i)
        {
            months[i].setMonth(monthNames[i - 1], i);
        }
    }

    Bill &getbill(int month)
    {
        return months[month];
    }
};


class Year
{ 
    public: 
     
    Months *yearMonths;
    int year;
    int YearlyTotal = 0;
    int YearlyCredit = 0;
    int payment = YearlyTotal - YearlyCredit;

    Year() { }
    Year(int num)
    {
        year = num;
        yearMonths = new Months();
    }

    void setYearlyTotal(int value)
    {
        YearlyTotal = YearlyTotal + value;
    }

    void setYearlyCredit(int value)
    {
        YearlyCredit = YearlyCredit + value;
    }

    int getYearlyCredit()
    {
        return YearlyCredit;
    }
    int getYearlyTotal()
    {
        return YearlyTotal;
    }
};

class Years
{ 
       public:   
   
      Years() { }
  
     Year years[50];
    int hash(int numYear)
    {
        return numYear % 50;
    }

    void insertYear(int numYear)
    {
        years[hash(numYear)] = Year(numYear);
    }

    Year & getYear(int year)
    {
        return years[hash(year)];
    }
}; 

#endif