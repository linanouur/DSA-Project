#ifndef CUSTOMERSAVL_H
#define CUSTOMERSAVL_H

#include <iostream>
#include <string>
#include "customer.h" 
#include "customer.cpp"




class CustomersAVL
{
private:
    Customer *rootCus;
    static int maxAmountInjected;
    static int maxInjectorID;
    static string cityWinner;
    static string regionWinner;
    static string districtWinner; 
    void displayOneMonthBillsALL(Customer *ptr, int, int);
    void displayOneYearBillsALL(Customer *ptr, int);
    void displayPeriodBillsALL(Customer *ptr, int, int , int , int); 
    Customer *insert2(Customer *, Customer *); 
    Customer *searchCustomer(int, Customer *); 
  
    

    int height(Customer *);
    int getBalance(Customer *);
    Customer *rRotate(Customer *);
    Customer *lRotate(Customer *); 
     void printInorder(Customer *);
    
public:
      CustomersAVL() : rootCus(nullptr) {}
     void insertNewCustomerAVL(Customer *);

    void setInfoCustomerOneMonthAVL(int , int , int , Bill &);
    void getOneMonthBillAVL(int, int, int);
    void getOneYearBillAVL(int, int);
    void getPeriodBillAVL(int, int, int, int, int);
    Customer *searchCustomer(int);
   
   
   
  


    static void setInfoNewInjector(int, int, string, string, string);
    void printLevelOrder(); 
    void print(); 
    static int getmaxInjectorID();
    static int getmaxAmoutInjected(); 
    static void displayWinner();
    void displayOneMonthBillsALLPub(int, int);
    void displayOneYearBillsALLPub(int);
    void displayOnePeriodBillsALLPub(int, int, int, int); 


      
};
#endif