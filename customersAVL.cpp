#ifndef CUSTOMERSAVL_CPP
#define CUSTOMERSAVL_CPP
#include <iostream>
#include <string>
#include "customersAVL.h"
#include "customer.h"
#include "customers.h"
#include "customers.cpp"
#include "calendar.cpp"
#include "bills.cpp"
#include "bills.h"
#include "userFunctions.cpp"
#include <fstream>
#include <sstream>
#include <vector> 
#include <iomanip> 

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
void CustomersAVL::insertNewCustomer2(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id ) {
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    rootCus = insert2(rootCus, cus);
}

Customer *CustomersAVL::searchCustomer(int ID, Customer *r)
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
void CustomersAVL::insertNewCustomerAVL(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id ) {
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    rootCus = insert2(rootCus, cus);
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
        cout.width(10);
        cout << current->firstName;
        cout.width(20);
        cout << current->FamilyName;
        cout.width(10);
        cout << current->ElectricityAccountId << endl;
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
} 
void CustomersAVL::printInorderAVL(Customer *ptr)
{
    if (ptr == NULL)
        return;

    printInorderAVL(ptr->left);

    cout.width(10);
    cout << ptr->firstName;
    cout.width(20);
    cout << ptr->FamilyName;
    cout.width(10);
    cout << ptr->ElectricityAccountId << endl;

    printInorderAVL(ptr->right);
}
void CustomersAVL::printAVL()
{
    printInorderAVL(rootCus);
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



int main()
{
  CustomersAVL *AVL= new CustomersAVL(); 
  
    AVL->insertNewCustomer2("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar" , 53);   
    AVL->insertNewCustomer2("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 43);
    AVL->insertNewCustomer2("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123); 
    AVL->insertNewCustomer2("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 23); 
    AVL->insertNewCustomer2("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 63);
    AVL->insertNewCustomer2("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 80);
    AVL->printAVL();// Outputs the ElectricityAccountId values of the customers 

    cout << "enter customer id" << endl;
    int id;
    cin >> id;
    cout << getRegionId(id) << endl;
    cout << getCityId(id) << endl;
    cout << getDistrictId(id) << endl;
    cout << getCustomerID(id) << endl;

    return 0;
} 

#endif
