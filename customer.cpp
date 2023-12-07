#include <iostream>
#include <string>
#include "customer.h"
#include "bills.cpp"
using namespace std;

Customer ::Customer(string fname, string lname, int ElecId, int bankAccount = 0, int numMemb, vector<int> ages, string region, string city, string district)
{
    Years = new Years();
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

Customer *Customers ::searchCustomer(int ID, Customer *r)
{
    if (r == NULL)
        return NULL;

    else if (ID == r->ElectricityAccountId)
        return r;

    Customer *search(int ID, Customer *r)
    {
        if (ID < r->ElectricityAccountId)
            search(ID, r->left);

        else
            search(ID, r->right);
    }
}

Customer *Customers ::searchCustomer(int ID)
{
    return searchCustomer(ID, rootCus);
}

static void Customers ::setInfoNewInjector(int ID, int newValue)
{
    maxInjectorID = ID;
    maxAmountInjected = newValue;
}

static int Customers ::getMaxInjectorID()
{
    return maxInjectorID;
}

static int Customers ::getMaxAmoutInjected()
{
    return maxAmountInjected;
}

void displayOneMonthBill(int id, int year, int month)
{
    Customer *cust = searchCustomer(id);
    Year *y = cust->getYear(year);
    Month *m = y->getMonth(month);
    m->MonthlyBill.displayBill();
}

// void displayOneYearBill(int id, int year)
// {
//     displayPeriodBill(year, year, 1, 12);
// }

// void displayPeriodBill(int id, int yearStart, int yearEnd, int MonthStart, int MonthEnd)
// {
    
// }