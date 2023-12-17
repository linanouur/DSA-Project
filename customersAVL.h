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
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;

    Customer *insert2(Customer *, Customer *);
    void insertNewCustomer2(string, string, int, int, string, string, string, int);
    Customer *searchCustomer(int, Customer *);
    Customer *searchCustomer(int);
    int height(Customer *);
    int getBalance(Customer *);
    Customer *rRotate(Customer *);
    Customer *lRotate(Customer *);
    static void setInfoNewInjector(int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void print();
    void printLevelOrder();
    void printInorderAVL(Customer *);
    void printAVL();
    void printInorder(Customer *);
};
#endif