#ifndef CUSTOMERS_CPP
#define CUSTOMERS_CPP
#include <iostream>
#include <string>
#include "customer.h"
#include "customers.h"
#include "calendar.cpp"
#include "bills.cpp"
#include "bills.h"
#include "userFunctions.cpp"
#include <fstream>
#include <sstream>
#include <vector> 
#include <iomanip> 


using namespace std;

int Customers ::maxInjectorID = 0;
int Customers ::maxAmountInjected = 0;
string Customers ::regionWinner = "";
string Customers ::cityWinner = "";
string Customers ::districtWinner = "";

int getPrize(Customers *BST)
{
    cout << "The winner ID: ";
    return BST->Customers ::getmaxInjectorID();
}


void Customers::insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, vector<int> Ages, string region, string city, string district) {
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, Ages, region, city, district);
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
    Customers ::maxInjectorID = ID;
    Customers ::maxAmountInjected = newValue;
    Customers ::regionWinner = RW;
    Customers ::cityWinner = CW;
    Customers ::districtWinner = DW;
}

int Customers ::getmaxInjectorID()
{
    return Customers ::maxInjectorID;
}

int Customers ::getmaxAmoutInjected()
{
    return Customers ::maxAmountInjected;
}

void Customers ::displayWinner()
{
    cout << "The winner of this month is: " << endl;
    cout << "ID Winner: " << Customers ::maxInjectorID << endl;
    // cout << "From: " << regionWinner << "  " << cityWinner << "  " << districtWinner << endl;
    cout << "with an injection Amount : " << Customers ::maxAmountInjected << endl;
}

int main()
{
    Customers BST; 
    vector<int> Ages = { 20, 30, 40 };   


     /*BST.insertNewCustomer("John", "Doe", 12345, 3,Ages,"Adrar", "Adrar", "Adrar");
    BST.insertNewCustomer("Jane", "Doe", 67890, 1,Ages,"South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678, 4,Ages, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456, 2,Ages,"West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012, 5,Ages, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543, 2,Ages, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567, 4,Ages ,"East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345, 1,Ages, "West", "Annaba", "El Bouni");
    BST.print(); // Outputs the ElectricityAccountId values of the customers */
    

    cout << "enter customer id" << endl;
    int id;
    cin >> id;  
   
   
    cout<<getCustomerID(id)<<endl;  

    cout<<getDistrictId(id)<<endl;
    cout<<getCityId(id)<<endl;
    cout<<getRegionId(id)<<endl;
   


    // Customer *cust = BST.searchCustomer(67890);
    // if (cust != nullptr)
    // {
    //     cust->Customeryears->insertYear(1950);
    //     Year &y = cust->Customeryears->getYear(1950);
    //     Bill &m = y.yearMonths->getbill(3);
    //     cout << "Month number: " << m.numberMonth << endl;
    // }
    // else
    // {
    //     cout << "Customer not found." << endl;
    // }
    cout<<"hello world";
    return 0;
}

#endif