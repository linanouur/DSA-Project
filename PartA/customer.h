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
    long long int BankAccount;
    int familyMembersNumber;
    int *Ages;
    int totalInjection = 0;  //total injection is set by default to 0 as an initial value
    Years *Customeryears;  //each customer is linked to a hash table of years to manage his billings
    string Region;
    string City;
    string District;
    bool haveInjectedBefore;
    Customer *left;
    Customer *right;
    int id;

    Customer() {}
    Customer(string, string,long long int, int, int* A , string, string, string,long long int);
    void setInfo(string, string, long long int, int,int* A, string, string, string);
    vector<string> getIDs(string, string, string);  //function used to generate ID
    string getConcatenatedIDs(string, string, string); //function used to generate ID
    long long int generateCustomerID(string, string, string, long int); //function used to generate ID
    void settotalInjection(int);
    long long int getCustomerId();
    void getOneMonthBillCustomer(int, int);
    void getOneYearBillCustomer(int);
    void getPeriodBillCustomer(int, int, int, int);
};

#endif
