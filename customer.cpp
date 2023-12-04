#include <iostream>
#include <string>
#include "Customers.h"
#include "bills.h"
using namespace std;

Customer ::Customer(string fname, string lname, int ElecId, int bankAccount = 0, int numMemb, vector<int> ages, string region, string city, string district)
{
    setInfo(fname, lname, ElecId, bankAccount = 0, numMemb, ages, region, city, district);
}