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


int main()
{
  CustomersAVL *AVL= new CustomersAVL(); 
  
    AVL->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar" , 53);   
    AVL->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 43);
    AVL->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123); 
    AVL->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 23); 
    AVL->insertNewCustomer("Ahmed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 63);
    AVL->insertNewCustomer("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 80);
    AVL->printAVL();// Outputs the ElectricityAccountId values of the customers 

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
