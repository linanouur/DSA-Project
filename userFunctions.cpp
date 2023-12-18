#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP

#include <iostream>
#include<string>
#include "Regions.h"
#include"Regions.cpp"
#include "City.h"
#include"City.cpp"
#include "District.h"
#include"District.cpp"
#include "customers.h"
#include "customers.cpp"
#include "customer.h"
#include "customer.cpp"
#include "calendar.cpp"
#include "bills.h"
#include"bills.cpp"
using namespace std;

int getRegionId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string regionID;
    if (CustomerIDString.length() == 10)
    {

        regionID = CustomerIDString.substr(0, 1);
    }
    else
    {
        regionID = CustomerIDString.substr(0, 2);
    }
    return stoi(regionID);
}
int getCityId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string cityID;
    if (CustomerIDString.length() == 10)
    {
        cityID = CustomerIDString.substr(1, 2);
    }
    else
    {
        cityID = CustomerIDString.substr(2, 2);
    }
    return stoi(cityID);
}
int getDistrictId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string districtID;
    if (CustomerIDString.length() == 10)
    {
        districtID = CustomerIDString.substr(3, 3);
    }
    else
    {
        districtID = CustomerIDString.substr(4, 3);
    }

    return stoi(districtID);
}
int getCustomerID(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string customerID;

    if (CustomerIDString.length() == 10)
    {
        customerID = CustomerIDString.substr(6, 4);
    }
    else
    {
        customerID = CustomerIDString.substr(7, 4);
    }

    return stoi(customerID);
}

void insertNewCustomer(htRegions Alg, string fname, string lname, int bankAccount, int numMemb, string region, string city, string district, int id)
{
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    long int NewID = cus->generateCustomerID(region, city, district, id);
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District *Dptr = Cptr->Districts->getDistrict(D);
    Dptr->BST->insertNewCustomerBST(cus);
}

void setInfoOneMonth(htRegions Alg, int ID, int month, int year, int Mconsumption, int Minjection)
{
    Bill bill;
    bill.setBillInfo(Mconsumption, Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District *Dptr = Cptr->Districts->getDistrict(D);
    Dptr->BST->setInfoCustomerOneMonthBST(ID, month, year, bill);
}

void getOnemonthBill(htRegions Alg, int ID, int month, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District *Dptr = Cptr->Districts->getDistrict(D);
    Dptr->BST->getOneMonthBillBST(ID, month, year);
}

void getOneYearBill(htRegions Alg, int ID, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District *Dptr = Cptr->Districts->getDistrict(D);
    Dptr->BST->getOneYearBillBST(ID, year);
}

void getPeriodBill(htRegions &Alg, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District *Dptr = Cptr->Districts->getDistrict(D);
    Dptr->BST->getPeriodBillBST(ID, monthStart, monthEnd, yearStart, yearEnd);
}



int main()
{
    htRegions regionHashTable;
 ifstream file("RegionCityDistrict.csv"); 

   if (file.is_open()) {
       string line;
       while (getline(file, line)) {
           stringstream ss(line);
            string regionID, regionName, cityID, cityName, districtID, districtName;

            getline(ss, regionID, ',');
            getline(ss, regionName, ',');
            getline(ss, cityID, ',');
            getline(ss, cityName, ',');
            getline(ss, districtID, ',');
            getline(ss, districtName, ',');
            int RegionID, CityID, DistrictID;
            RegionID=stoi(regionID);
            CityID=stoi(cityID);
            DistrictID=stoi(districtID);
           regionHashTable.insertRegion(Region(RegionID, regionName));
            regionHashTable.insertCity(RegionID, City(CityID, cityName));
            regionHashTable.insertDistrict(RegionID, CityID, District(DistrictID, districtName));

        }
        file.close();

    } else {
        cout << "Unable to open file." << endl;
    }

    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123);
     /*insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1236, 5, "Adrar", "Adrar", "Adrar", 2); 
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 13456, 5, "Adrar", "Adrar", "Adrar", 3);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1256, 5, "Adrar", "Adrar", "Adrar", 4); */
    //setInfoOneMonth(regionHashTable, 1010010123, 1, 2020, 100, 100);  
    //getOnemonthBill(regionHashTable, 1010010123, 1, 2020);  
    cout<<getCustomerID(1010010123)<<endl;

   
    
  

   

    return 0;
}

#endif