#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

Customer ::Customer(string fname, string lname, int ElecId, int bankAccount = 0, int numMemb, vector<int> ages, string region, string city, string district)
{
    setInfo(fname, lname, ElecId, bankAccount = 0, numMemb, ages, region, city, district);
}

void Customer ::setInfo(string fname, string lname, int ElecId, int bankAccount = 0, int numMemb, vector<int> ages, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    ElectricityAccountId = ElecId;
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
    Ages = ages;
    Region = region;
    City = city;
    District = district;
}



