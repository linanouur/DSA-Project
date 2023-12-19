#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <iostream>
#include<string>

#include"bills.cpp"
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
    int height;
    int id;


    Customer(string, string, int, int, string, string, string ,int );
    void setInfo(string, string, int, int, string, string, string); 
    vector<string> getIDs( string , string, string); 
    string getConcatenatedIDs(string, string, string); 
    long int  generateCustomerID(string,string,string,int);
    void settotalInjection(int);
    long int getCustomerId();
    void getOneMonthBillCustomer(int , int);
    void getOneYearBillCustomer(int);
    void getPeriodBillCustomer( int , int , int , int );
}; 

class Customers
{
private:
    Customer *rootCus;

    Customer *insert(Customer *, Customer *);
    Customer *searchCustomer(int, Customer *);
    void printInorder(Customer *);
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner;

public:
    Customers() : rootCus(nullptr){}
    void insertNewCustomerBST(Customer *);
    void setInfoCustomerOneMonthBST( int , int , int, Bill &);
    void getOneMonthBillBST( int , int , int );
    void getOneYearBillBST( int , int );
    void getPeriodBillBST( int , int , int , int , int);
    Customer *searchCustomer(int);
    void print();
    static void setInfoNewInjector(int, int, string, string, string);
    static int getmaxInjectorID();
    static int getmaxAmoutInjected();
    static void displayWinner();
    void printLevelOrder();
};
#endif