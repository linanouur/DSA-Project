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


int main()
{
    /*Customers BST;
    BST.insertNewCustomer("John", "Doe", 12345,12345, 3,"North", "Mahelma", "Bouira");
    BST.insertNewCustomer("Jane", "Doe", 67890,67890, 1, "South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678,45678, 4, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456,23456, 2, "West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012,89012, 5, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543,76543, 2, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567,34567, 4, "East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345,12345, 1, "West", "Annaba", "El Bouni");
    BST.print(); 
    cout << endl;*/

    cout << "enter customer id" << endl;
    int id;
    cin >> id;
    cout << getRegionId(id) << endl;
    cout << getCityId(id) << endl;
    cout << getDistrictId(id) << endl;
    cout << getCustomerID(id) << endl;

    /*Customer *cust = BST.searchCustomer(67890);
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
    }*/
    return 0;
}
#endif
