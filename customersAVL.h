#ifndef CUSTOMERSAVL_H
#define CUSTOMERSAVL_H

#include <iostream>
#include <string>
#include"calendar.cpp"
#include"customerAVL.h"
using namespace std;

class Customers
{
private:
    Customer *rootCus;

    Customer *insert(Customer *, Customer *);
    Customer *searchCustomer(int, Customer *);
    void printInorder(Customer *);
    int height(Customer*);
    int getBalance(Customer*);
    Customer* rRotate(Customer*);
    Customer* lRotate(Customer*);
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;

public:
    void insertNewCustomer(string, string, int, int, int, string, string, string);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int , int , string , string , string );
    static int getmaxInjectorID();
    static int getmaxAmoutInjected ();
    static void displayWinner();
};
#endif