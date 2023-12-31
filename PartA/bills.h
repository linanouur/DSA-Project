#ifndef BILLS_H
#define BILLS_H
#include <iostream>
#include <string>
#include <vector>

// Enum class representing the status of a bill
enum class status
{
    calculated,
    NotCalculatedYet
};

class Bill
{
public:
    // Member variables
    std::string monthName;
    int numberMonth;
    double Total = 0; // Total To be paid by customer
    double MonthConsumptionAmount;
    double MonthInjectionAmount;
    double MonthlyCredit = 0;                    // credit that a customer can get in case of injection
    bool MonthTransferCreditByBank;           // In case of injection and the amount of injection was larger than the amount of consumption,customer will get that difference by Bank
    status state = status ::NotCalculatedYet; // state of a bill is by default notCalculatedYet 

    // Member Functions
    Bill();
    void setMonth(std::string, int); // set the bill's monthNumber and its name
    void setBillInfo(double, double);      // setting the amounts of consumption and injection
    double CalculateBill(double, double);     // A function that calculate the Total of the bill and assign its credit
    double getTotal();
    void displayBill(); // print the bill's details
    void operator=(const Bill &other);  // Overloaded assignment operator for the Bill class
};

#endif