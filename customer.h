#ifndef CUSTOMER_H
#define CUSTOMER_H 
 #include <iostream>
#include <string>
#include"calendar.cpp"
using namespace std;

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
<<<<<<< HEAD
};

#endif
=======
}; 
#endif
>>>>>>> 89e6cb082b8338e03ce6dc4c69a700893b36485e
