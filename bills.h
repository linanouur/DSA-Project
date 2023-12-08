#include <iostream>
#include <string>
#include <vector>
#include "customer.cpp"

enum class status
{
    calculated,
    NotCalculatedYet
};

class Bill : public Customer, public Month, public Year
{
protected:
    int Total = 0;
    int MonthConsumptionAmount;
    int MonthInjectionAmount;
    bool MonthTransferCreditByBank;
    int MonthlyCredit = 0;
    status state = status ::NotCalculatedYet;
    int CalculateBill(int , int );

public:
    Bill();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    void setBillInfo(int , int );
    void displayBill();
    int getTotal();
};

