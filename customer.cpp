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

void Customers ::insertNewCustomer(string fname, string lname, int ElecId, int bankAccount = 0, int numMemb, vector<int> ages, string region, string city, string district)
{
    Customer *cus = new Customer(fname, lname, ElecId, bankAccount = 0, numMemb, ages, region, city, district);
    root = insert(rootCus, cus);
}
bool Customers ::searchCustomer(int)
{
}

Customer *Customers ::insert(Customer *root, Customer *node)
{
    if (root == NULL)
    {
        return node;
    }
    else if (node->ElectricityAccountId <= root->ElectricityAccountId)
    {
        insert(root->left, node);

        else insert(root->right, node);
    }
}

Customer *Customers ::searchCustomer(int ID)
{
    if (r == NULL)
        return NULL;
    else
        return search(ID, root);

    if (ID == r->ElectricityAccountId)
        return r;
    Customer *search(int ID, Customer *r)
    {
        if (ID < r->ElectricityAccountId)
            search(ID, r->left);

        else
            search(ID, r->right);
    }
}

void Customer ::displayOneMonthBill(int year, int month)
{
    displayPeriodBill(year, year, month, month);
}

void Customer ::displayOneYearBill(int year)
{
    displayPeriodBill(year, year, 1, 12);
}

void Customer::displayPeriodBill(int yearStart, int yearEnd, int MonthStart, int MonthEnd){
    for(int i=yearStart,i<=yearEnd;i++){
        for(int k=MonthStart;k<12;k++){
(Years->year[hash(i)].yearMonths->months[k] ).monthgetBill();  //not Completed Yet
}
    }
    
}
