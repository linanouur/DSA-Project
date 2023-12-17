#ifndef BILLS_CPP
#define BILLS_CPP

#include <iostream>
#include <string>
#include "bills.h"
using namespace std;

Bill ::Bill()
{
    MonthConsumptionAmount = 0;
    MonthInjectionAmount = 0;
    state = status::NotCalculatedYet;
}

void Bill ::setBillInfo(int ConsumptionAmount, int InjectionAmount)
{
    MonthConsumptionAmount = ConsumptionAmount;
    MonthInjectionAmount = InjectionAmount;
}

int Bill ::CalculateBill(int ConsumptionAmount, int InjectionAmount)
{
    if (InjectionAmount == 0)
    {
        Total = 5 * ConsumptionAmount;
        state = status::calculated;
        return Total;
    }

    int difference = 5 * ConsumptionAmount - 3 * InjectionAmount;
    state = status::calculated;
    if (difference > 0)
    {
        Total = difference;
        MonthTransferCreditByBank = false;
        return Total;
    }

    else
    {
        MonthlyCredit = difference * (-1);
        MonthTransferCreditByBank = true;
        Total = 0;
        return Total;
    }
}

int Bill::getTotal()
{
    if (state == status::NotCalculatedYet)
        return CalculateBill(MonthConsumptionAmount, MonthInjectionAmount);
    else
        return Total;
}

void Bill ::displayBill()
{
    cout << "Monthly Amount Consumption: " << MonthConsumptionAmount << " Killowatt Hours " << endl;
    cout << "Monthly Amount Injection: " << MonthInjectionAmount << " Killowatt Hours " << endl;
    cout << "Monthly Credit: " << MonthlyCredit << " " << endl;
    cout << " Total to Be Paid: " << getTotal() << " " << endl;
}

void Bill ::operator=(const Bill &other)
{
    this->MonthConsumptionAmount = other.MonthConsumptionAmount;
    this->MonthInjectionAmount =  other.MonthInjectionAmount ;
}

#endif
