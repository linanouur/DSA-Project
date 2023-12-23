#ifndef BILLS_CPP
#define BILLS_CPP

#include <iostream>
#include <string>
#include <vector>
#include "bills.h"
using namespace std;

Bill ::Bill() // default constructor
{
    MonthConsumptionAmount = 0;
    MonthInjectionAmount = 0;
    state = status::NotCalculatedYet;
}

void Bill ::setMonth(std::string name, int num)
{
    monthName = name;
    numberMonth = num;
}

void Bill ::setBillInfo(double ConsumptionAmount, double InjectionAmount)
{
    MonthConsumptionAmount = ConsumptionAmount;
    MonthInjectionAmount = InjectionAmount;
}

double Bill ::CalculateBill(double ConsumptionAmount, double InjectionAmount)
{
    if (InjectionAmount == 0) 
    {
        Total = 5 * ConsumptionAmount;   //if the injection is null so the total will be calculated as 5*ConsumptionAmount
        state = status::calculated;
        return Total;  
    }

    double difference = 5 * ConsumptionAmount - 3 * InjectionAmount;  

    if (difference > 0)  //This means that The amount to be paid is larger than the credit
    {
        Total = difference;  //Customer pay the difference
        MonthTransferCreditByBank = false; //the credit is smaller than the amount to be paid so customer pay this amount
        state = status::calculated;
        return Total;
    }

    else   // the credit is larger than the amount of consumption*5
    {
        MonthlyCredit = difference * (-1); 
        MonthTransferCreditByBank = true; // the difference will be transfered uby bank
        Total = 0; //customer will pay nothing
        state = status::calculated;
        return Total;
    }
}

double Bill::getTotal()
{
    if (state == status::NotCalculatedYet)  //the 
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
    this->MonthInjectionAmount = other.MonthInjectionAmount;
}

#endif