#include <iostream>
#include <string>
#include "customer.h"
#include "bills.cpp"
using namespace std;

Customers ::maxAmountInjected = 0;
Customers ::maxInjectorID = 0;
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

void Customers::insertNewCustomer(string fname, string lname, int ElecId, int bankAccount, int numMemb, string region, string city, string district)
{
    Customer *cus = new Customer(fname, lname, ElecId, bankAccount, numMemb, region, city, district);
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
    cout << "\t" << ptr->ElectricityAccountId << "\t";
    printInorder(ptr->right);
}

void Customers::print()
{
    printInorder(rootCus);
}

int main()
{
    Customers BST;
    BST.insertNewCustomer("John", "Doe", 12345, 54321, 3, "North", "Mahelma", "Bouira");
    BST.insertNewCustomer("Jane", "Doe", 67890, 21345, 1, "South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678, 87654, 4, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456, 12345, 2, "West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012, 98765, 5, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543, 89012, 2, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567, 56789, 4, "East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345, 34567, 1, "West", "Annaba", "El Bouni");
    BST.print(); // Outputs the ElectricityAccountId values of the customers

    return 0;
}

// void displayOneMonthBill(int id, int year, int month)
// {
//     Customer *cust = searchCustomer(id);
//     Year *y = cust->getYear(year);
//     Month *m = y->getMonth(month);
//     m->MonthlyBill.displayBill();
// }

// void displayOneYearBill(int id, int year)
// {
//     displayPeriodBill(year, year, 1, 12);
// }

// void displayPeriodBill(int id, int yearStart, int yearEnd, int MonthStart, int MonthEnd)
// {

// }