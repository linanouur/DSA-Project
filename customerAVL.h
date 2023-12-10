#ifndef CUSTOMERSAVL_H
#define CUSTOMERSAVL_H

#include <iostream>
#include <string>
#include"calendar.cpp"
using namespace std;


struct Customer
{
    string firstName;
    string FamilyName;
    int ElectricityAccountId;
    int BankAccount;
    int familyMembersNumber;
    int totalInjection = 0;
    Years *Customeryears;
    string Region;
    string City;
    string District;
    bool haveInjectedBefore;
    Customer *left;
    Customer *right;
    int height;

    Customer(string, string, int, int, int, string, string, string);
    void setInfo(string, string, int, int, int, string, string, string);
    void setTotalInjection(int);
    int getCustomerId();
    
};


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

public:
    void insertNewCustomer(string, string, int, int, int, string, string, string);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int , int);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected ();
};

#endif