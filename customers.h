#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <iostream>
#include<string>

#include"bills.cpp"
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
    Customers() : rootCus(nullptr){}
    void insertNewCustomerBST(Customer *);
    void setInfoCustomerOneMonthBST( int , int , int, Bill &);
    void getOneMonthBillBST( int , int , int );
    void getOneYearBillBST( int , int );
    void getPeriodBillBST( int , int , int , int , int);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void printLevelOrder();
};
#endif