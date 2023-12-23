#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP
#include<iomanip>
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
#include "customer.cpp"
#include "calendar.cpp"
#include "bills.h"
#include "bills.cpp"
#include "Departments.h"
#include "Departments.cpp"
#include "weatherHashTable.h"
#include "weatherHashTable.cpp"
#include "w_year.h"
#include "w_year.cpp"
#include "w_month.h"
#include "w_month.cpp"
#include "w_day.h"
#include "w_day.cpp"
#include "weather.h"

using namespace std;

using namespace std;

int getRegionIDfromFile(string region)
{
    ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return -1;
    }

    while (getline(file, line))
    {
        istringstream lineStream(line);
        IDSorNames.clear();

        while (getline(lineStream, IDorName, ','))
        {
            IDSorNames.push_back(IDorName);
        }

        if (IDSorNames.size() >= 6 &&
            IDSorNames[1] == region)
        {

            return stoi(IDSorNames[0]);
        }
    }

    return -1;
}
int getCityIDfromFile(string city)
{
    ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return -1;
    }

    while (getline(file, line))
    {
        istringstream lineStream(line);
        IDSorNames.clear();

        while (getline(lineStream, IDorName, ','))
        {
            IDSorNames.push_back(IDorName);
        }

        if (IDSorNames.size() >= 6 && IDSorNames[3] == city)
        {

            return stoi(IDSorNames[2]);
        }
    }

    return -1;
}
int getDistrictIDfromFile(string district)
{
    ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return -1;
    }

    while (getline(file, line))
    {
        istringstream lineStream(line);
        IDSorNames.clear();

        while (getline(lineStream, IDorName, ','))
        {
            IDSorNames.push_back(IDorName);
        }

        if (IDSorNames.size() >= 6 && IDSorNames[5] == district)
        {
            return stoi(IDSorNames[4]);
        }
    }

    return -1;
}

int getRegionId( long int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string regionID;
    if (CustomerIDString.length() == 15)
    {

        regionID = CustomerIDString.substr(0, 1);
    }
    else
    {
        regionID = CustomerIDString.substr(0, 2);
    }
    return stoi(regionID);
}
int getCityId( long int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string cityID;
    if (CustomerIDString.length() == 15)
    {
        cityID = CustomerIDString.substr(1, 2);
    }
    else
    {
        cityID = CustomerIDString.substr(2, 2);
    }
    return stoi(cityID);
}
int getDistrictId( long int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string districtID;
    if (CustomerIDString.length() == 15)
    {
        districtID = CustomerIDString.substr(3, 3);
    }
    else
    {
        districtID = CustomerIDString.substr(4, 3);
    }

    return stoi(districtID);
}
int getCustomerID( long int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string customerID;

    if (CustomerIDString.length() == 15)
    {
        customerID = CustomerIDString.substr(6, 9);
    }
    else
    {
        customerID = CustomerIDString.substr(7, 9);
    }

    return stoi(customerID);
}

void insertNewCustomer(htRegions Alg, string fname, string lname, int bankAccount, int numMemb, int *ages, string region, string city, string district,long int id)
{
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, ages, region, city, district, id);
    long int NewID = cus->ElectricityAccountId;
    int R = getRegionId(NewID);
    cout<<R<<endl;
    int C = getCityId(NewID);
    cout<<C<<endl;
    int D = getDistrictId(NewID);
    cout<<D<<endl;
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->insertNewCustomerBST(cus);
    std::cout << "\t\t"
    << "^" << setfill(' ') << setw(40) << "Custumer added successfully" << setw(19) << "^" << endl;
}

void setInfoOneMonth(htRegions &HReg,  long int ID, int month, int year, int Mconsumption, int Minjection)
{
    bool exists = false;
    Bill bill;
    bill.setBillInfo(Mconsumption, Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = HReg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->setInfoCustomerOneMonthBST(ID, month, year, bill, exists);
    if (exists == true)
    {
        int difference = 5 * Mconsumption - 3 * Minjection;
        Cptr->setInfoDepartment(month, year, difference, Minjection);
    }
}

void getOnemonthBill(htRegions &Alg,long int ID, int month, int year)
{
    cout << "hello";
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    cout << "Phase 1" << endl;
    B->getOneMonthBillBST(ID, month, year);
}

void getOneYearBill(htRegions Alg,long int ID, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->getOneYearBillBST(ID, year);
}

void getPeriodBill(htRegions &Alg,long int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->getPeriodBillBST(ID, monthStart, monthEnd, yearStart, yearEnd);
}

void getOneMonthBillCountry(htRegions &Alg, int month, int year)
{
    Alg.getOneMonthBillinRegions(month, year);
}

void getOneMonthBillRegion(htRegions &Alg, string RegionName, int month, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    Region *R = Alg.getRegion(RegionID);
    R->getOneMonthBillinRegion(month, year);
}

void getOneMonthBillCity(htRegions &Alg, string RegionName, string CityName, int month, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getOneMonthBillinCity(month, year);
}

void getOneMonthBillDistrict(htRegions &Alg, string RegionName, string CityName, string DistrictName, int month, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    int DistrictID = getRegionIDfromFile(DistrictName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getOneMonthBillinDistrict(month, year);
}

void getOneYearBillCountry(htRegions &Alg, int year)
{
    Alg.getOneYearBillinRegions(year);
}

void getOneYearBillRegion(htRegions &Alg, string RegionName, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    Region *R = Alg.getRegion(RegionID);
    R->getOneYearBillinRegion(year);
}

void getOneYearBillCity(htRegions &Alg, string RegionName, string CityName, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getOneYearBillinCity(year);
}

void getOneYearBillDistrict(htRegions &Alg, string RegionName, string CityName, string DistrictName, int year)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    int DistrictID = getRegionIDfromFile(DistrictName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getOneYearBillinDistrict(year);
}

void getOnePeriodBillCountry(htRegions &Alg, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    Alg.getPeriodBillinRegions(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodBillRegion(htRegions &Alg, string RegionName, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int RegionID = getRegionIDfromFile(RegionName);
    Region *R = Alg.getRegion(RegionID);
    R->getPeriodBillinRegion(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodBillCity(htRegions &Alg, string RegionName, string CityName, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getPeriodBillinCity(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodBillDistrict(htRegions &Alg, string RegionName, string CityName, string DistrictName, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int RegionID = getRegionIDfromFile(RegionName);
    int CityID = getCityIDfromFile(CityName);
    int DistrictID = getRegionIDfromFile(DistrictName);
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getPeriodBillinDistrict(monthStart, monthEnd, yearStart, yearEnd);
}

#endif