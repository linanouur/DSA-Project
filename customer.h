#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include"calendar.cpp" 
using namespace std;


class Customer
{
    public:
    string firstName;
    string FamilyName;
    int ElectricityAccountId;
    int BankAccount;
    int familyMembersNumber;
    vector<int> familyAges;
    int totalInjection = 0;
    Years *Customeryears;
    string Region;
    string City;
    string District;
    bool haveInjectedBefore;
    Customer *left;
    Customer *right;

    Customer(string, string, int, int, vector<int>,  string, string, string);
    void setInfo(string, string, int, int, vector<int> , string, string, string); 
    vector<string> getIDs( string , string, string); 
    string getConcatenatedIDs(string, string, string); 
    int  generateCustomerID();
    void settotalInjection(int);
    int getCustomerId();
    
}; 
#endif
