#ifndef CALENDAR_CPP
#define CALENDAR_CPP

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "bills.cpp"

using namespace std;

class Months
{
public:
    Bill months[13];
    Months()
    { // setting the months of the year
        const string monthNames[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"};

        for (int i = 1; i <= 12; ++i)
        {
            months[i].setMonth(monthNames[i - 1], i);
        }
    }

    // returning the exact address of any month
    Bill *getbill(int month)
    {
        return &months[month];
    }
};

class Year
{
public:
    Months *yearMonths; // each year is linked to a hashtable of Bills(each one is concerning one month)
    int year;
    int YearlyTotal = 0;
    int YearlyCredit = 0;
    int payment = YearlyTotal - YearlyCredit;

    Year() {}
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
    Year years[50];
    Years() {}

    int hash(int numYear)   //hashing the years in the hash table 
    {
        return numYear % 50;
    }

    void insertYear(int numYear)
    {
        years[hash(numYear)] = Year(numYear);
    }

    Year *getYear(int year)
    {
        return &years[hash(year)];
    }
};

#endif