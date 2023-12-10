#ifndef CUSTOMERS_CPP
#define CUSTOMERS_CPP

#include <iostream>
#include <string>
#include "customer.h" 
#include "customers.h"
#include "calendar.cpp"
#include "bills.cpp"  
#include"userFunctions.cpp"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int getPrize(Customers *BST)
{
    cout << "The winner ID: ";
    return BST->getmaxInjectorID();
}

void Customers :: insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
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

int main()
{
    Customers BST;
    BST.insertNewCustomer("John", "Doe", 12345, 3, "North", "Mahelma", "Bouira");
    BST.insertNewCustomer("Jane", "Doe", 67890, 1, "South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678, 4, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456, 2, "West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012, 5, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543, 2, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567, 4, "East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345,  1, "West", "Annaba", "El Bouni");
    BST.print(); // Outputs the ElectricityAccountId values of the customers
    cout << endl;

    cout << "enter customer id" << endl;
    int id;
    cin >> id;
    cout << getRegionId(id) << endl;
    cout << getCityId(id) << endl;
    cout << getDistrictId(id) << endl;
    cout << getCustomerID(id) << endl;

    Customer *cust = BST.searchCustomer(67890);
    if (cust != nullptr)
    {
        cust->Customeryears->insertYear(1950);
        Year &y = cust->Customeryears->getYear(1950);
        Bill &m = y.yearMonths->getbill(3);
        cout << "Month number: " << m.numberMonth << endl;
    }
    else
    {
        cout << "Customer not found." << endl;
    }
    return 0;
}


#endif