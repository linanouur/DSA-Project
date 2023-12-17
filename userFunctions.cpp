#include <iostream>
#include <string>
#include "Regions.h"
using namespace std;


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



void insertNewCustomer(htRegions alg , string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id){
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    long int NewID = cus->generateCustomerID(region,city,district,id);
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    Region *Rptr=alg.getRegion(R);
    City *Cptr = Rptr->region_cities->getCity(C);
    District *Dptr = Cptr->city_disricts->getDistrict(D);
    Dptr->BST->insertNewCustomerBST(cus);
}



void setInfoOneMonth(htRegions Alg ,int ID , int month , int year , int Mconsumption , int Minjection){
    Bill bill;
    bill.setBillInfo(Mconsumption,Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    
}

void getOnemonthBill(htRegions Alg ,int ID, int month, int year){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
   
}

void getOneYearBill(htRegions Alg , int ID , int year){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
   
}

void getPeriodBill( htRegions &Alg , int ID , int monthStart, int monthEnd, int yearStart, int yearEnd){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    
}
