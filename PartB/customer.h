#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include "calendar.cpp"
using namespace std;

class Customer
{
public:
    string firstName;
    string FamilyName;
    long long int ElectricityAccountId;
    int BankAccount;
    int familyMembersNumber;
    int *Ages;
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
    Customer(string, string, int, int, int* A , string, string, string,long long int);
    void setInfo(string, string, int, int,int* A, string, string, string);
    vector<string> getIDs(string, string, string);
    string getConcatenatedIDs(string, string, string);
    long long int generateCustomerID(string, string, string, long int);
    void settotalInjection(int);
    long int getCustomerId();
    void getOneMonthBillCustomer(int, int);
    void getOneYearBillCustomer(int);
    void getPeriodBillCustomer(int, int, int, int);
};

#endif

