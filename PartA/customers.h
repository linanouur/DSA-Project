#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <iostream>
#include <string>
#include "customer.cpp"
#include "bills.cpp"
#include "customer.h"
using namespace std;

class Customers // BST based
{
private:
    Customer *rootCus;
    static double maxAmountInjected;
    static long long int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;
    Customer *insert(Customer *, Customer *);
    Customer *searchCustomer(long long int, Customer *);
    void printInorder(Customer *);
    void displayOneMonthBillsALL(Customer *ptr, int, int);
    void displayOneYearBillsALL(Customer *ptr, int);
    void displayPeriodBillsALL(Customer *ptr, int, int, int, int);

public:
    Customers() : rootCus(nullptr) {}
    void insertNewCustomerBST(Customer *);
     Customer *searchCustomer(long long int);
    void print();
    void printLevelOrder();
    void setInfoCustomerOneMonthBST(long long int, int, int, Bill &, bool &doesExist);
    void getOneMonthBillBST(long long int, int, int);
    void getOneYearBillBST(long long int, int);
    void getPeriodBillBST(long long int, int, int, int, int);
    static void setInfoNewInjector(long long int, double, string, string, string);
    static long long int getmaxInjectorID();
    static double getmaxAmoutInjected();
    static void displayWinner();
    void displayOneMonthBillsALLPub(int, int);
    void displayOneYearBillsALLPub(int);
    void displayOnePeriodBillsALLPub(int, int, int, int);
};
#endif