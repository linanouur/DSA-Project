#include <iostream>
#include <string>
#include"calendar.cpp"
#include"customer.h"
using namespace std;

enum class status
{
    calculated,
    NotCalculatedYet
};

struct Customer {
    string firstName;
    string FamilyName;
    int ElectricityAccountId;
    int BankAccount;
    int familyMembersNumber;
    Years *Customeryears;
    string Region;
    string City;
    string District;
    bool haveInjectedBefore;
    Customer *left;
    Customer *right;

    Customer(string, string, int, int, int,  string, string, string);
    void setInfo(string, string, int, int, int,  string, string, string);
};

class Customers {
private:
    Customer *rootCus;

    Customer *insert(Customer *, Customer *);
    Customer *searchCustomer(int, Customer *);
    void printInorder(Customer *);

public:
    void insertNewCustomer(string, string, int, int, int, string, string, string);
    Customer *searchCustomer(int);
    void print();
};