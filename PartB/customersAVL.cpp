#ifndef CUSTOMERSAVL_CPP
#define CUSTOMERSAVL_CPP

#include <iostream>
#include "customer.h"
#include "customersAVL.h" 
#include <queue>

using namespace std;

int CustomersAVL ::maxInjectorID = 0;
int CustomersAVL ::maxAmountInjected = 0;
string CustomersAVL ::regionWinner = "";
string CustomersAVL ::cityWinner = "";
string CustomersAVL ::districtWinner = "";

Customer *CustomersAVL::insert2(Customer *root, Customer *node)
{
    if (root == nullptr)
    {
        return node;
    }
    else if (node->ElectricityAccountId <= root->ElectricityAccountId)
    {
        root->left = insert2(root->left, node);
    }
    else
    {
        root->right = insert2(root->right, node);
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && node->ElectricityAccountId < root->left->ElectricityAccountId)
        return rRotate(root);
    if (balance < -1 && node->ElectricityAccountId > root->right->ElectricityAccountId)
        return lRotate(root);
    if (balance > 1 && node->ElectricityAccountId > root->left->ElectricityAccountId)
    {
        root->left = lRotate(root->left);
        return rRotate(root);
    }
    if (balance < -1 && node->ElectricityAccountId < root->right->ElectricityAccountId)
    {
        root->right = rRotate(root->right);
        return lRotate(root);
    }
    return root;
}
void CustomersAVL::insertNewCustomerAVL(Customer *ptr)
{
    rootCus = insert2(rootCus, ptr);
}

Customer *CustomersAVL::searchCustomer(int ID, Customer *r)
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

Customer *CustomersAVL::searchCustomer(int ID)
{
    return searchCustomer(ID, rootCus);
}
int CustomersAVL::height(Customer *node)
{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int CustomersAVL::getBalance(Customer *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Customer *CustomersAVL::rRotate(Customer *y)
{
    Customer *x = y->left;
    Customer *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Customer *CustomersAVL::lRotate(Customer *x)
{
    Customer *y = x->right;
    Customer *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
} 


 
 void CustomersAVL::printLevelOrder()
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


void CustomersAVL::printInorder(Customer *ptr)
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
void CustomersAVL::print()
{
    printInorder(rootCus);
}   

void CustomersAVL::setInfoCustomerOneMonthAVL(long long int ID, int month, int year, Bill &other, bool &doesExist)
{
    Customer *cust = searchCustomer(ID);
    if (cust != nullptr)
    {
        cust->settotalInjection(other.MonthInjectionAmount);
        if (cust->totalInjection > getmaxAmoutInjected())
            setInfoNewInjector(ID, cust->totalInjection, cust->Region, cust->City, cust->District);
        Year *y = cust->Customeryears->getYear(year);
        y->setYearlyTotal(other.MonthConsumptionAmount * 5);
        y->setYearlyCredit(other.MonthInjectionAmount * 3);
        Bill *m = y->yearMonths->getbill(month);
        m->MonthConsumptionAmount= other.MonthConsumptionAmount;
        m->MonthInjectionAmount =other.MonthInjectionAmount;
        doesExist = true;
    }
    else
    {
        doesExist = false;
        cout << "Customer not found." << endl;
    }
}
void CustomersAVL::displayOneMonthBillsALL(Customer *ptr, int month, int year)
{
    if (ptr == NULL)
    {
        return;
    }

    displayOneMonthBillsALL(ptr->left, month, year);

    ptr->getOneMonthBillCustomer(month, year);

    displayOneMonthBillsALL(ptr->right, month, year);
}
void CustomersAVL::displayOneMonthBillsALLPub(int month, int year)
{
    displayOneMonthBillsALL(rootCus, month, year);
}   
void CustomersAVL::displayPeriodBillsALL(Customer *ptr, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    if (ptr == NULL)
    {
        return;
    }

    displayPeriodBillsALL(ptr->left, monthStart, monthEnd, yearStart, yearEnd);

    ptr->getPeriodBillCustomer(monthStart, monthEnd, yearStart, yearEnd);

    displayPeriodBillsALL(ptr->right, monthStart, monthEnd, yearStart, yearEnd);
}   
void CustomersAVL::displayOnePeriodBillsALLPub(int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    displayOnePeriodBillsALLPub(monthStart, monthEnd, yearStart, yearEnd);
}
void CustomersAVL::displayOneYearBillsALL(Customer *ptr, int year)
{
    if (ptr == NULL)
    {
        return;
    }

    displayOneYearBillsALL(ptr->left, year);

    ptr->getOneYearBillCustomer(year);

    displayOneYearBillsALL(ptr->right, year);
}
void CustomersAVL::displayOneYearBillsALLPub(int year)
{
    displayOneYearBillsALL(rootCus, year);
}


void CustomersAVL ::setInfoNewInjector(int ID, int newValue, string RW, string CW, string DW)
{
 CustomersAVL ::maxInjectorID = ID;
    CustomersAVL ::maxAmountInjected = newValue;
    CustomersAVL ::regionWinner = RW;
    CustomersAVL ::cityWinner = CW;
    CustomersAVL ::districtWinner = DW;
}

int CustomersAVL ::getmaxInjectorID()
{
    return CustomersAVL ::maxInjectorID;
}

int CustomersAVL ::getmaxAmoutInjected()
{
    return CustomersAVL ::maxAmountInjected;
}
int getPrize(CustomersAVL *AVL)
{
    cout << "The winner ID: ";
    return AVL->CustomersAVL ::getmaxInjectorID();
}

void CustomersAVL ::displayWinner()
{
    cout << "The winner of this month is: " << endl;
    cout << "ID Winner: " << CustomersAVL ::maxInjectorID << endl;
    // cout << "From: " << regionWinner << "  " << cityWinner << "  " << districtWinner << endl;
    cout << "with an injection Amount : " << CustomersAVL ::maxAmountInjected << endl;
}

void CustomersAVL ::getOneMonthBillAVL(int ID, int month, int year)
{
    cout << "Bill of " << month
         << " / " << year << " : " << endl;
    Customer *cust = searchCustomer(ID);
    cout << cust->ElectricityAccountId;
    if (cust != nullptr)
    {
        cust->getOneMonthBillCustomer(month, year);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void CustomersAVL ::getOneYearBillAVL(int ID, int year)
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

void CustomersAVL ::getPeriodBillAVL(int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
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



#endif
