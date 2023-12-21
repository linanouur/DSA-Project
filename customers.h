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
    Customer *searchCustomer(int, Customer *);
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
    void displayPeriodBillsALL(Customer *ptr, int, int , int , int);
public:
    Customers() : rootCus(nullptr) {}
    void insertNewCustomerBST(Customer *);
    void setInfoCustomerOneMonthBST(int ID, int month, int year, Bill &other)
    {

        Customer *cust = searchCustomer(ID);
        cout << cust->firstName << endl;
        if (cust != nullptr)
        {
            cust->settotalInjection(other.MonthInjectionAmount);
            if (cust->totalInjection > getmaxAmoutInjected())
                setInfoNewInjector(ID, cust->totalInjection, cust->Region, cust->City, cust->District);
            Year *y = cust->Customeryears->getYear(year);
            cout << y->getYearlyCredit() << endl;
            cout << y->getYearlyTotal() << endl;
            y->setYearlyTotal(other.MonthConsumptionAmount * 5);
            y->setYearlyCredit(other.MonthInjectionAmount * 3);
            Bill &m = y->yearMonths->getbill(month);
            m = other;
        }
        else
        {
            cout << "Customer not found." << endl;
        }
    }
    void getOneMonthBillBST(int, int, int);
    void getOneYearBillBST(int, int);
    void getPeriodBillBST(int, int, int, int, int);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void printLevelOrder();
    void displayOneMonthBillsALLPub(int, int);
    void displayOneYearBillsALLPub(int);
    void displayOnePeriodBillsALLPub(int, int, int, int);
};
#endif