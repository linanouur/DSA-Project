#include <iostream>
#include <string>
#include "Regions.h"
#include "Regions.cpp"
#include "City.h"
#include "City.cpp"
#include "District.h"
#include "District.cpp"
#include "customers.h"
#include "customers.cpp"
#include "customer.h"
#include"customer.cpp"
#include "calendar.cpp"
#include "bills.h"
#include "bills.cpp"
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

    Region region1(1, "Region1");
    Region region2(2, "Region2");
    regionHashTable.insertRegion(region1);
    htDistricts districtHashTable;
    District district1(1, "District1");
    District district2(2, "District2");
    District district3(3, "District3");
    District district4(4, "District4");
    htCities cityHashTable;
    City city1(1, "City1");
    City city2(2, "City2");
    City city3( 3,"city3");
    City city4( 3,"city4");
    City city5( 3,"city5");
    regionHashTable.insertCity(1, city1);
    regionHashTable.insertCity(1, city3);
    regionHashTable.insertCity(1, city4);
    regionHashTable.insertCity(2, city5);
    regionHashTable.insertCity(2, city2);
    regionHashTable.insertDistrict(1, 1, district1);
    regionHashTable.insertDistrict(1, 1, district2);
    regionHashTable.insertDistrict(2, 1, district3);
    regionHashTable.insertDistrict(2, 2, district4);
    regionHashTable.displaycities(1);

    return 0;
}