#ifndef CUSTOMERAVL_H
#define CUSTOMERAVL_H

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

#endif
