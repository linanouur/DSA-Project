#ifndef CUSTOMERS_CPP
#define CUSTOMERS_CPP
#include <iostream>
#include "customer.h"
#include "customers.h"
#include <queue>
using namespace std;

int Customers ::maxInjectorID = 0;
int Customers ::maxAmountInjected = 0;
string Customers ::regionWinner = "";
string Customers ::cityWinner = "";
string Customers ::districtWinner = "";

// Customers ::Customers()
// {
//   rootCus=new Customer("Lina", "Slama", 123456, 5, "Adrar", "Adrar", "Ouled Ahmed Timmi", 1320);
// }

int getPrize(Customers *BST)
{
    cout << "The winner ID: ";
    return BST->Customers ::getmaxInjectorID();
}

void Customers::insertNewCustomerBST(Customer *ptr)
{
    cout << "hey";
    rootCus = insert(rootCus, ptr);
}

Customer *Customers::insert(Customer *root, Customer *node)
{
    if (root == nullptr)
    {
        return node;
    }
    else if (node->ElectricityAccountId <= root->ElectricityAccountId)
    {
        cout << root->ElectricityAccountId << endl;
        cout << node->ElectricityAccountId << endl;
        root->left = insert(root->left, node);
        return root;
    }
    else
    {
        cout << node->firstName << endl;
        root->right = insert(root->right, node);
        return root;
    }
}

Customer *Customers::searchCustomer(int ID, Customer *r)
{

    if (r == nullptr)
    {
        return r;
    }
    else if (r->ElectricityAccountId == ID)
    {
        cout << r->FamilyName << endl;
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
}

Customer *Customers::searchCustomer(int ID)
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

void Customers ::getOneMonthBillBST(int ID, int month, int year)
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

void Customers ::getOneYearBillBST(int ID, int year)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
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

void Customers ::getPeriodBillBST(int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << monthStart << " / " << yearStart << " : "
         << "/t"
         << "To: " << monthEnd << " / " << yearEnd;
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

/*
int main(){
    Customers BST;
    Customer N("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123);
    Customer M("Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Ouled Ahmed Timmi", 123);
    Customer H( "Lina", "Slama", 123456, 5, "Adrar", "Adrar", "Ouled Ahmed Timmi", 150);

    BST.insertNewCustomerBST(&N);
    cout<<"Hello";
    BST.insertNewCustomerBST(&M);
    BST.insertNewCustomerBST(&H);
    // if(BST ) cout<<"it's not null"<<endl;
    // else cout<<" null"<<endl;
    // BST.print();

  Customer *cus = BST.searchCustomer(1010010123);
  cout<<cus->FamilyName<<endl;
  cout<<cus->City<<endl;
  BST.print();
//   Bill b;
//   b.setBillInfo(100,50);
// BST.setInfoCustomerOneMonthBST(1010010123,10,2024,b);
// cout<<endl;
// BST.getOneMonthBillBST(1010010123,10,2024);
    // Customer *K=nullptr;
    // if(K==nullptr) cout<<"not  found";
    // K= BST.searchCustomer(1010010123);

    //  if(K!=nullptr) cout<<"M";


    return 0;
}
*/
#endif
