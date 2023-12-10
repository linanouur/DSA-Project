#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <iostream>
#include <string>
#include <vector>
#include"calendar.cpp" 
#include"customer.h"
using namespace std;
 class Customers
{
private:
    Customer *rootCus;

    Customer *insert(Customer *, Customer *);
    Customer *searchCustomer(int, Customer *);
    void printInorder(Customer *);
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;


public:
    void insertNewCustomer(string, string, int, int, string, string, string );
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int , int , string , string , string );
    static int getmaxInjectorID();
    static int getmaxAmoutInjected ();
    static void displayWinner();
}; 
#endif