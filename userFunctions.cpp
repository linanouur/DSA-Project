#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP

#include <iostream>
#include<string>
#include "customer.cpp"
#include "customers.cpp"
#include "customers.h"
#include "calendar.cpp"
#include "bills.cpp" 
#include <fstream>
#include <sstream>
#include <vector>
#include"userFunctions.cpp"
#include "newRCD.cpp"
using namespace std;


RegionHashTable Alg;


int getRegionId(int CustomerID)
{  
    string CustomerIDString = to_string(CustomerID);  
    string regionID; 
    if(CustomerIDString.length() == 10) { 
        
     regionID = CustomerIDString.substr(0,1);  
    }  
    else 
    {
    regionID = CustomerIDString.substr(0,2);
    } 
    return stoi(regionID);
}
int getCityId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID); 
    string cityID;  
    if(CustomerIDString.length() == 10) { 
        cityID = CustomerIDString.substr(1,2);  
    }  
    else 
    {
    cityID = CustomerIDString.substr(2,2); 
    }
    return stoi(cityID);
}
int getDistrictId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string districtID ;   
    if(CustomerIDString.length() == 10) { 
        districtID = CustomerIDString.substr(3,3);  
    }  
    else 
    { 
    districtID = CustomerIDString.substr(4,3);
     }
  
    return stoi(districtID);
}
int getCustomerID(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string customerID ;  

    if(CustomerIDString.length() == 10) { 
        customerID = CustomerIDString.substr(6,4);  
    }  
    else 
    { customerID = CustomerIDString.substr(7,4); } 

    return stoi(customerID);
}



void getOneYearBill(Customers *BST, int ID, int year)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << year << " : " << endl;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        for (int month = 1; month < 13; month++)
        {
            Bill &m = y.yearMonths->getbill(month);
            cout << "Month " << month << endl;
            m.displayBill();
        }
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void getPeriodBill(Customers *BST, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << monthStart << " / " << yearStart << " : "
         << "/t"
         << "To: " << monthEnd << " / " << yearEnd;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        if (yearStart == yearEnd)
        {
            Year &y = cust->Customeryears->getYear(yearStart);
            for (int month = monthStart; month < monthEnd; month++)
            {
                Bill &m = y.yearMonths->getbill(month);
                cout << "Month " << month << endl;
                m.displayBill();
            }
            return;
        }

        for (int year = yearStart; year <= yearEnd; year++)
        {
            Year &y = cust->Customeryears->getYear(year);
            for (int month = 1; month < 13; month++)
            {
                if (year = yearEnd && month > monthEnd)
                    break;
                Bill &m = y.yearMonths->getbill(month);
                m.displayBill();
            }
        }
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}




void insertNewCustomer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id){
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    long int NewID = cus->generateCustomerID(region,city,district,id);
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    Alg.addCustomerToDistrict(R,C,D,cus);
}



void setInfoOneMonth(int ID , int month , int year , int Mconsumption , int Minjection){
    Bill bill;
    bill.setBillInfo(Mconsumption,Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.setInfoMonthCustomerRegion(R , C , D, ID, month, year, bill);
}

void getOnemonthBill(int ID, int month, int year){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.getOnemonthBillR(R , C , D, ID, month, year);
}


#endif