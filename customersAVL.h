#ifndef CUSTOMERSAVL_H
#define CUSTOMERSAVL_H

#include <iostream>
#include <string>
#include "calendar.cpp"
#include "customer.h"
using namespace std;

class CustomersAVL
{
public:
    Customer *rootCus;

    Customer *insert2(Customer *, Customer *);
    Customer *searchCustomer(int, Customer *);
    void printInorder(Customer *);
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;
    int height(Customer *);
    int getBalance(Customer *);
    Customer *rRotate(Customer *);
    Customer *lRotate(Customer *);
    void insert2(string, string, int, int, int, string, string, string);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void insertNewCustomer(string , string, int , int , string , string , string ,int );
};
#endif