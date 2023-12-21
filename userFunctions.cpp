#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP

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
    long int NewID = cus->ElectricityAccountId;
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    // cout << R << endl;
    // cout << C << endl;
    // cout << D << endl;
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->insertNewCustomerBST(cus);
    // Cptr->Districts->insertCustomerIntoDistrict(Dis, cus);
    // Customer *nas = Dis.BST.searchCustomer(NewID);
    // cout << nas->District << endl;
    Dis.BST.print();

    // Dis.BST.insertNewCustomerBST(cus);
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
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->setInfoCustomerOneMonthBST(ID, month, year, bill);

    // cout<<Dis.DistrictID<<endl;
    // Cptr->Districts->setInfoInDistrict(Dis,ID,month,year,bill);

    // District *Dptr = Cptr->Districts->getDistrict(D);
    //    Dis.setInfoCustomerOneMonthBST(ID,month,year,bill);
    //    cout<<"cc";
    //   District *Dptr = Cptr->Districts->getDistrictptr(D);
    // Dptr->BST.setInfoCustomerOneMonthBST(ID,month,year,bill);
    // Dptr->BST.setInfoCustomerOneMonthBST(ID, month, year, bill);
}

void getOnemonthBill(htRegions Alg, int ID, int month, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCity(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->getOneMonthBillBST(ID, month, year);
}

// void getOneYearBill(htRegions Alg, int ID, int year)
// {
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//      District Dis=Cptr->Districts->getDistrict(D);
//     Dis.BST.getOneYearBillBST(ID,year);
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.getOneYearBillBST(ID, year);
// }

// void getPeriodBill(htRegions &Alg, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
// {
//     int R = getRegionId(ID);
//     int C = getCityId(ID);
//     int D = getDistrictId(ID);
//     Region *Rptr = Alg.getRegion(R);
//     City *Cptr = Rptr->Cities->getCity(C);
//      District Dis=Cptr->Districts->getDistrict(D);
//     Dis.BST.getPeriodBillBST(ID,monthStart,monthEnd,yearStart,yearEnd);
//     // District *Dptr = Cptr->Districts->getDistrict(D);
//     // Dptr->BST.getPeriodBillBST(ID, monthStart, monthEnd, yearStart, yearEnd);
// }

int main()
{
    htRegions regionHashTable;
    // regionHashTable.insertRegion(Region(1,"Adrar"));
    // regionHashTable.insertCity(1,City(1,"Adrar"));
    // regionHashTable.insertCity(2,City(2,"Chlef"));
    // regionHashTable.insertDistrict(1,1,District(1,"Adrar"));
    ifstream file("RegionCityDistrict.csv");

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string regionID, regionName, cityID, cityName, districtID, districtName;

            getline(ss, regionID, ',');
            getline(ss, regionName, ',');
            getline(ss, cityID, ',');
            getline(ss, cityName, ',');
            getline(ss, districtID, ',');
            getline(ss, districtName, ',');
            int RegionID, CityID, DistrictID;
            RegionID = stoi(regionID);
            CityID = stoi(cityID);
            DistrictID = stoi(districtID);
            regionHashTable.insertRegion(Region(RegionID, regionName));
            regionHashTable.insertCity(RegionID, City(CityID, cityName));
            regionHashTable.insertDistrict(RegionID, CityID, District(DistrictID, districtName));
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 123);
    insertNewCustomer(regionHashTable, "Moh", "Ali", 1236, 5, "Adrar", "Adrar", "Adrar", 2);
    insertNewCustomer(regionHashTable, "Mo", "Ali", 13456, 5, "Adrar", "Adrar", "Adrar", 3);
    insertNewCustomer(regionHashTable, "Ahmed", "Ali", 1256, 5, "Adrar", "Adrar", "Adrar", 4);
    insertNewCustomer(regionHashTable, "Moha", "Ali", 123456, 5, "Adrar", "Adrar", "Adrar", 150);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1236, 5, "Adrar", "Adrar", "Adrar", 1);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 13456, 5, "Adrar", "Adrar", "Adrar", 90);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1256, 5, "Adrar", "Adrar", "Adrar", 180);

    Region *Rptr = regionHashTable.getRegion(1);
    City *Cptr = Rptr->Cities->getCity(1);
    // Cptr->Districts->displayAllDistricts();

    // cout << D.DistrictName << endl;
    District Dis = Cptr->Districts->getDistrict(1);
    Dis.BST.print();
    cout << "mmmmmm" << endl;
    // Customer *nas = D.searchinDistrict(1010010002);
    // if(nas==nullptr) cout<<"null"<<endl;
    // else cout << nas->FamilyName << endl;

    Customers *B = Cptr->Districts->getBST(1);
    Customer *nas = B->searchCustomer(1010010002);
    if (nas == nullptr)
        cout << "null" << endl;
    else
        cout << nas->FamilyName << endl;
    setInfoOneMonth(regionHashTable, 1010010002, 1, 2023, 100, 100);
    getOnemonthBill(regionHashTable, 1010010002, 1, 2023);
    setInfoOneMonth(regionHashTable, 1010010123, 1, 2023, 100, 100);
    setInfoOneMonth(regionHashTable, 1010010003, 1, 2023, 100, 100);
    setInfoOneMonth(regionHashTable, 1010010004, 1, 2023, 100, 100);

    B->displayOneMonthBillsALLPub(1, 2023);
    // cout << getCustomerID(1010010123) << endl;
    // cout << getCustomerID(1010010002) << endl;
    // cout << getCustomerID(1010010003) << endl;
    // cout << getCustomerID(1010010004) << endl;

    // Region *R = regionHashTable.getRegion(1);
    // // cout<<R->RegionName<<endl;
    // // R->Cities->displaycities();
    // City *C = R->Cities->getCity(1);

    // District DISTRICT = C->Districts->getDistrict(1);

    // cout << "MMMM" << endl;
    // Customer *cust = C->Districts->searchCustomerinHD(1,1010010123);
    // cout << cust->firstName << endl;
    // cout << "MMMMM" << endl;
    // DISTRICT.BST.print();
    // Customers BST;
    // BST.displayWinner();

    // htCities htc;
    // City c1(1,"Adrar");

    // htc.insertCity(c1);

    // Department d1 = c1.department;
    // double budget= d1.getBudget();
    // cout << "Budget of d1: " << budget << endl;

    return 0;
}*/
#endif