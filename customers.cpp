#ifndef CUSTOMERS_CPP
#define CUSTOMERS_CPP
#include <queue>
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

void Customers::insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id ) {
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
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

void Customers::printLevelOrder()
{
    if (rootCus == nullptr)
        return;

    std::queue<Customer *> q;
    q.push(rootCus);

    while (!q.empty())
    {
        Customer *current = q.front();
        q.pop();

        // Print the customer information
        std::cout.width(10);
        std::cout << current->firstName;
        std::cout.width(20);
        std::cout << current->FamilyName;
        std::cout.width(10);
        std::cout << current->ElectricityAccountId << std::endl;

        // Enqueue left and right children if they exist
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
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

/*int main()
{
   Customers *BST = new Customers(); 
    BST->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar" , 53);   
    BST->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 43);
    BST->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123); 
    BST->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 23); 
    BST->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 63);
    BST->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 80);
    BST->printLevelOrder();
    
    
    
    cout<< "enter customer id" << endl;
    int id;
    cin >> id;

    cout << getCustomerID(id) << endl;

    cout << getDistrictId(id) << endl;
    cout << getCityId(id) << endl;
    cout << getRegionId(id) << endl;

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
    cout << "hello world";
    return 0;
}*/  


#endif 
