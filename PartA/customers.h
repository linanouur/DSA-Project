#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <iostream>
#include <string>
#include "customer.cpp"
#include "bills.cpp"
#include "customer.h"
using namespace std;

class Customers
{
private:
    Customer *searchCustomer(long long int, Customer *);
    void printInorder(Customer *);
    Customer *rootCus;
    Customer *insert(Customer *, Customer *);
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;
    void displayOneMonthBillsALL(Customer *ptr, int, int);
    void displayOneYearBillsALL(Customer *ptr, int);
    void displayPeriodBillsALL(Customer *ptr, int, int, int, int);
    int CustomersNum;

public:
    Customers() : rootCus(nullptr) {}
    void insertNewCustomerBST(Customer *);
    void setInfoCustomerOneMonthBST(long long int, int, int, Bill &, bool &doesExist);
    void getOneMonthBillBST(long long int, int, int);
    void getOneYearBillBST(long long int, int);
    void getPeriodBillBST(long long int, int, int, int, int);
    Customer *searchCustomer(long long int);
    void print();
    static void setInfoNewInjector(long long int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void printLevelOrder();
    void displayOneMonthBillsALLPub(int, int , bool &);
    void displayOneYearBillsALLPub(int , bool &);
    void displayOnePeriodBillsALLPub(int, int, int, int , bool &);
};
#endif