#include <iostream>
#include <string>
#include <vector>
#include "customer.cpp"

struct Month
{
    string monthName;
    int numberMonth;
    Bill MonthlyBill;

    Month(string name, int num)
    {
        monthName = name;
        numberMonth = num;
    }
};

struct Months
{
    Month months[13];
    Months()
    {
        const string monthNames[] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"};

        for (int i = 1; i <= 12; ++i)
        {
            months[i] = Month(monthNames[i], i);
        }
    }

    Month& getMonth(int month) {
        return months[hash(month)];
    }
};

struct Year
{
    int YearlyTotal = 0;
    int YearlyInjectionAmount;
    int YearlyCredit = 0;
    int payment = YearlyTotal - YearlyCredit;
    Months *yearMonths;
    int year;
    Year(int num)
    {
        year = num;
        yearMonths = new Months();
    }
};

struct Years
{
    Year years[50];
    int hash(int numYear)
    {
        return numYear % 50;
    }

    // void insertYear(int numYear)
    // {
    //     years[hash(numYear)] = Year(numYear);
    // }

    Year& getYear(int year) {
        return years[hash(year)];
    }
};