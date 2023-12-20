#ifndef BILLS_H
#define BILLS_H

#include <iostream>
#include <string>
using namespace std;

enum class status
{
    calculated,
    NotCalculatedYet
};

class Bill
{
    public:
    std::string monthName;
    int numberMonth;
    int Total = 0;
    int MonthConsumptionAmount;
    int MonthInjectionAmount;
    bool MonthTransferCreditByBank;
    int MonthlyCredit = 0;
    status state = status ::NotCalculatedYet;

    int CalculateBill(int, int);
    
    // Constructor
    Bill();

    void setMonth(string name, int num)
    {
        monthName = name;
        numberMonth = num;
    }

    void setBillInfo(int, int );
    void displayBill();
    int getTotal();
    void operator = (const Bill &other);
};

#endif