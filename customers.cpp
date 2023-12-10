#include <iostream>
#include <string>
#include "Customer.h"
#include "calendar.cpp"
#include "bills.cpp"
using namespace std;

void Customers::insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district);
    rootCus = insert(rootCus, cus);
}

Customer *Customers::insert(Customer *root, Customer *node)
{
    if (root == nullptr)
    {
        return node;
    }
    else if (node->ElectricityAccountId <= root->ElectricityAccountId)
    {
        root->left = insert(root->left, node);
    }
    else
    {
        root->right = insert(root->right, node);
    }
    return root;
}

Customer *Customers::searchCustomer(int ID, Customer *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    else if (ID == r->ElectricityAccountId)
    {
        return r;
    }
    else if (ID < r->ElectricityAccountId)
    {
        return searchCustomer(ID, r->left);
    }
    else
    {
        return searchCustomer(ID, r->right);
    }
}

Customer *Customers::searchCustomer(int ID)
{
    return searchCustomer(ID, rootCus);
}

void Customers::printInorder(Customer *ptr)
{
    if (ptr == NULL)
        return;

    printInorder(ptr->left);

    cout.width(10);
    cout << ptr->firstName;
    cout.width(20);
    cout << ptr->FamilyName;
    cout.width(10);
    cout << ptr->ElectricityAccountId << endl;

    printInorder(ptr->right);
}

void Customers::print()
{
    printInorder(rootCus);
}

void Customers ::setInfoNewInjector(int ID, int newValue, string RW, string CW, string DW)
{
    maxInjectorID = ID;
    maxAmountInjected = newValue;
    regionWinner = RW;
    cityWinner = CW;
    districtWinner = DW;
}

int Customers ::getmaxInjectorID()
{
    return maxInjectorID;
}

int Customers ::getmaxAmoutInjected()
{
    return maxAmountInjected;
}

void Customers ::displayWinner()
{
    cout << "The winner of this month is: " << endl;
    cout << "ID Winner: " << maxInjectorID << endl;
    cout << "From: " << regionWinner << "  " << cityWinner << "  " << districtWinner << endl;
    cout << "with an injection Amount : " << maxAmountInjected << endl;
}