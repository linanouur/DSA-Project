#include <iostream>
#include <string>
#include <vector>

enum class status
{
    calculated,
    NotCalculatedYet
};

class Customer
{

protected:
    string firstName;
    string FamilyName;
    int ElectricityAccountId;
    int BankAccount;
    int Credit = 0;
    int familyMembersNumber;
    int totalInjection = 0;
    vector<int> Ages;
    string Region; // should have a pointer to the city,region,district that he belongs to , not a string
    string City;
    string District;
    bool haveInjectedBefore = false;
    Years *Years;
    Customer *left;
    Customer *right;
    // string unit;
    // int unitCons;
    // int unitInjec;

public:
    Customer(string, string, int, int = 0, int, vector<int>, string, string, string);
    void setInfo(string, string, int, int = 0, int, vector<int>, string, string, string);
    
};



class Customers
{
private:
    Customer *rootCus;
    int size=0;
    Customer * insert(Customer *, Customer *);
    Customer * searchCustomer(int , Customer *);
    static int maxAmountInjected=0;
    static int maxInjectorID=0;
public:
    void insertNewCustomer(string, string, int, int = 0, int, vector<int>, string, string, string);
    Customer *searchCustomer(int);
    static void setInfoNewInjector(int , int);
    static int get maxInjectorID();
    static int get maxAmoutInjected ();
    

};