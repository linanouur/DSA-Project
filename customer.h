#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include"calendar.cpp" 
using namespace std;

class Customer
{ public : 
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

    Customer(string, string, int, int,  string, string, string);
    void setInfo(string, string, int, int,  string, string, string); 
    vector<string> getIDs( string , string, string); 
    string getConcatenatedIDs(string, string, string); 
    long int  generateCustomerID(string,string,string);
     void settotalInjection(int);
     long int getCustomerId();
    
}; 
#endif
