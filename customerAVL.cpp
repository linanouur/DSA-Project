
#include <iostream>
#include <string>
#include "customerAVL.h"
#include "calendar.cpp"
#include "bills.cpp"
using namespace std;
void Customer ::setTotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{

    setInfo(fname, lname, ElecId, bankAccount, numMemb, region, city, district);
}

void Customer::setInfo(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    ElectricityAccountId = ElecId;
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
    Region = region;
    City = city;
    District = district;

    haveInjectedBefore = false;
    left = nullptr;
    right = nullptr;
}
