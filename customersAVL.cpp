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
void CustomersAVL::insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id ) {
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    rootCus = insert2(rootCus, cus);
}


int main()
{
    Customers *BST = new Customers(); 
    BST->insertNewCustomer("John", "Doe", 12345, 3, "Adrar", "Adrar", "Adrar", 53);
    BST->insertNewCustomer("Jane", "Doe", 67890, 1, "Adrar", "Adrar", "Adrar", 43);
    BST->insertNewCustomer("Emma", "Brown", 23456, 2, "Adrar", "Adrar", "Adrar", 123);
    BST->insertNewCustomer("Aisha", "Boudjemaa", 76543, 2, "Adrar", "Adrar", "Adrar", 23);
    BST->insertNewCustomer("Karim", "Belkacem", 34567, 4, "Adrar", "Adrar", "Adrar", 63);
    BST->insertNewCustomer("Karim", "Belkacem", 34567, 4, "Adrar", "Adrar", "Adrar", 80);
    BST->printLevelOrder(); // Outputs the ElectricityAccountId values of the customers 

    std::cout << "enter customer id" << endl;
    int id;
    std::cin >> id;
    std::cout << getRegionId(id) << endl;
    std::cout << getCityId(id) << endl;
    std::cout << getDistrictId(id) << endl;
    std::cout << getCustomerID(id) << endl;

    return 0;
}
#endif
