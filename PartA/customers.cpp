#ifndef CUSTOMERS_CPP
#define CUSTOMERS_CPP
#include <iostream>
#include "customer.h"
#include "customers.h"
#include <queue>
using namespace std;

//initializing static members of Customers class
int Customers ::maxInjectorID = 0;
int Customers ::maxAmountInjected = 0;
string Customers ::regionWinner = "";
string Customers ::cityWinner = "";
string Customers ::districtWinner = "";


void Customers::setInfoCustomerOneMonthBST(long long int ID, int month, int year, Bill &other, bool &doesExist)
{
    Customer *cust = searchCustomer(ID);
    if (cust != nullptr)  //if customer exist 
    {
        cust->settotalInjection(other.MonthInjectionAmount);  
        if (cust->totalInjection > getmaxAmoutInjected())  //comparing between the injection of the Best injector of all BSTs as it's a static member, so the injection is larger than the injection of the best injector : changing the values of the injector to avoid searching on it each time and accessing to all customers
            setInfoNewInjector(ID, cust->totalInjection, cust->Region, cust->City, cust->District);
        Year *y = cust->Customeryears->getYear(year);
        y->setYearlyTotal(other.MonthConsumptionAmount * 5); //setting customer information
        y->setYearlyCredit(other.MonthInjectionAmount * 3);
        Bill *m = y->yearMonths->getbill(month);
        m->MonthConsumptionAmount= other.MonthConsumptionAmount;
        m->MonthInjectionAmount =other.MonthInjectionAmount;
        doesExist = true;  //if customer exists in BST , this information is used by other functions that need to have an information about it
    }
    else
    {
        doesExist = false;
        cout << "Customer not found." << endl;
    }
}

void Customers::insertNewCustomerBST(Customer *ptr)
{
    rootCus = insert(rootCus, ptr);
}


Customer *Customers::insert(Customer *root, Customer *node)
{
    if (root == nullptr)
    {
        return node;
    }
    else if (node->ElectricityAccountId < root->ElectricityAccountId)
    {
        root->left = insert(root->left, node);
        return root;
    }
    else if (node->ElectricityAccountId > root->ElectricityAccountId)
    {
        root->right = insert(root->right, node);
        return root;
    }
    else if (node->ElectricityAccountId == root->ElectricityAccountId)
    {
        cout << "Customer already exists";
        return nullptr;
    }
    return nullptr;
}


Customer *Customers::searchCustomer(long long int ID, Customer *r)
{

    if (r == nullptr || r->ElectricityAccountId == ID)
    {
        return r;
    }

    else if (ID < r->ElectricityAccountId)
    {
        return searchCustomer(ID, r->left);
    }
    else if (ID > r->ElectricityAccountId)
    {
        return searchCustomer(ID, r->right);
    }
    return nullptr;
}

Customer *Customers::searchCustomer(long long int ID)
{
    return searchCustomer(ID, rootCus);
}

void Customers::printInorder(Customer *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    printInorder(ptr->left);

    cout.width(10);
    cout << ptr->firstName;
    cout.width(20);
    cout << ptr->FamilyName;
    cout.width(10);
    cout << ptr->ElectricityAccountId << endl;

    printInorder(ptr->right);
}

void Customers::displayOneMonthBillsALLPub(int month, int year, bool &exist)
{
    if(rootCus==nullptr) {
        exist = false;
    }
    else {displayOneMonthBillsALL(rootCus, month, year);}
   
}

void Customers::displayOneYearBillsALL(Customer *ptr, int year)
{
    if (ptr == NULL)
    {
        return;
    }

    displayOneYearBillsALL(ptr->left, year);

    ptr->getOneYearBillCustomer(year);

    displayOneYearBillsALL(ptr->right, year);
}

void Customers::displayPeriodBillsALL(Customer *ptr, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    if (ptr == NULL)
    {
        return;
    }

    displayPeriodBillsALL(ptr->left, monthStart, monthEnd, yearStart, yearEnd);

    ptr->getPeriodBillCustomer(monthStart, monthEnd, yearStart, yearEnd);

    displayPeriodBillsALL(ptr->right, monthStart, monthEnd, yearStart, yearEnd);
}

void Customers::displayOneYearBillsALLPub(int year , bool &exist)
{
     if(rootCus==nullptr) {
        exist = false;
    }
    else {
    displayOneYearBillsALL(rootCus, year);}
}
void Customers::displayOnePeriodBillsALLPub(int monthStart, int monthEnd, int yearStart, int yearEnd , bool &exist)
{
     if(rootCus==nullptr) {
        exist = false;
    }
    else {
    displayPeriodBillsALL( rootCus, monthStart, monthEnd, yearStart, yearEnd);}
}

void Customers::displayOneMonthBillsALL(Customer *ptr, int month, int year)
{
    
    if (ptr == NULL)
    {
        return;
    }

    displayOneMonthBillsALL(ptr->left, month, year);

    ptr->getOneMonthBillCustomer(month, year);

    displayOneMonthBillsALL(ptr->right, month, year);
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

void Customers ::setInfoNewInjector(long long int ID, int newValue, string RW, string CW, string DW)
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

void Customers ::getOneMonthBillBST(long long int ID, int month, int year)  //used to display bills for one month of customers that belong to the same district(Or BST)
{
    cout << "Bill of " << month << "  /  " << year << " : " << endl;
    Customer *cust = searchCustomer(ID);
    if (cust != nullptr)
    {
        cust->getOneMonthBillCustomer(month, year);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void Customers ::getOneYearBillBST(long long int ID, int year)
{
    cout << "Bill of " << year << " : " << endl;
    Customer *cust = searchCustomer(ID);
    if (cust != nullptr)
    {
        cust->getOneYearBillCustomer(year);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void Customers ::getPeriodBillBST(long long int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{

    cout << "Bill of " << monthStart << " / " << yearStart << " : "
         << " To: " << monthEnd << " / " << yearEnd << endl;
    Customer *cust = searchCustomer(ID);

    if (cust != nullptr)
    {
        cust->getPeriodBillCustomer(monthStart, monthEnd, yearStart, yearEnd);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void Customers ::displayWinner()
{
    cout << "The winner of this month is: " << endl;
    cout << "ID Winner: " << Customers ::maxInjectorID << endl;
    cout << "From: " << Customers::regionWinner << "  " << Customers::cityWinner << "  " << Customers::districtWinner << endl;
    cout << "with an injection Amount : " << Customers ::maxAmountInjected << endl;
}


int getPrize(Customers *BST)
{
    cout << "The winner ID: ";
    return BST->Customers ::getmaxInjectorID();
}


#endif
