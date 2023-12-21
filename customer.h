#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include "calendar.cpp"

class Customer
{
public:
    string firstName;
    string FamilyName;
    long int ElectricityAccountId;
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
    int id;

    Customer() {}
    Customer(string, string, int, int, string, string, string, int);
    void setInfo(string, string, int, int, string, string, string);
    vector<string> getIDs(string, string, string);
    string getConcatenatedIDs(string, string, string);
    long int generateCustomerID(string, string, string, int);
    void settotalInjection(int);
    long int getCustomerId();
    void getOneMonthBillCustomer(int, int);
    void getOneYearBillCustomer(int);
    void getPeriodBillCustomer(int, int, int, int);
};


#endif
