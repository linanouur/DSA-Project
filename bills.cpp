#include <iostream>
#include <string>
#include "customer.h"
#include "bills.h"
using namespace std;

Bill ::Bill(int ConsumptionAmount, int InjectionAmount, bool TransferCreditByBank)
{
    CalculateBill( ConsumptionAmount, InjectionAmount, TransferCreditByBank);
}

int Bill ::CalculateBill(int ConsumptionAmount, int InjectionAmount, bool TransferCreditByBank)
{

    MonthConsumptionAmount = ConsumptionAmount;
    MonthInjectionAmount = InjectionAmount;

    if (InjectionAmount == 0)
        Total = 5 * ConsumptionAmount;
    return Total;
    else if (TransferCreditByBank == false)
    {
        Total = 5 * ConsumptionAmount - 3 * InjectionAmount;
        return Total;
    }

    else
    {
        MonthlyCredit = MonthlyCredit + 3 * InjectionAmount;
        Total = 5 * ConsumptionAmount;
        return Total;
    }
    state = status::calculated;
}

int Bill::getTotal()
{
    if (state == status::empty)
        return CalculateBill(MonthConsumptionAmount, MonthInjectionAmount, MonthTransferCreditByBank);
    else
        return Total;
}

void Bill ::displayBill()
{
    cout << "Bill of " << numberMonth
         << " / " << year << " : " << endl;
    cout << "Customer: " << name << " , Electricity Account ID: " << ElectricityAccountId << endl;
    cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Monthly Amount Consumption: " << MonthConsumptionAmount << " Killowatt Hours " << endl;
    cout << "Monthly Amount Injection: " << MonthInjectionAmount << " Killowatt Hours " << endl;
    cout << "Monthly Credit: " << MonthlyCredit << " " << unit << endl;
    cout << " Total to Be Paid: " << getTotal() << " " << unit << endl;
}