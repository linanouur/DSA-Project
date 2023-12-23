#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP
#include <iomanip>
#include <iostream>
#include <vector>
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

int getRegionIDfromFile(string region)
{
    ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return -2;
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
        return -2;
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
        return -2;
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

int getRegionId(long long int CustomerID)
{
    std ::string CustomerIDString = std ::to_string(CustomerID);

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

int getCityId(long long int CustomerID)
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
int getDistrictId(long long int CustomerID)
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
int getCustomerID(long long int CustomerID)
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

void insertNewCustomer(htRegions Alg, string fname, string lname, long long int bankAccount, int numMemb, int *ages, string region, string city, string district, long long int id)
{
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, ages, region, city, district, id); // creating the Customer Node
    long long int NewID = cus->ElectricityAccountId;                                                    // new ID which is generated using the appropriate functions and called whithing the creation of the Customer Node
    int R = getRegionId(NewID);                                                                         // getting the Id of region
    int C = getCityId(NewID);                                                                           // getting the Id of city
    int D = getDistrictId(NewID);                                                                       // getting the Id of district
    Region *Rptr = Alg.getRegion(R);                                                                    // Access to region
    City *Cptr = Rptr->Cities->getCityptr(C);                                                           // Access to city
    District Dis = Cptr->Districts->getDistrict(D);                                                     // Access to district
    Customers *B = Cptr->Districts->getBST(D);
    B->insertNewCustomerBST(cus);             // access to the appropriate BST That customer belongs to and insert the Customer to it
    cout << "Customer Id: " << NewID << endl; // displaying the Id to the customer to use it other times
    std::cout << "\t\t"
              << "^" << setfill(' ') << setw(40) << "Custumer added successfully" << setw(19) << "^" << endl;
}

void insertNewCustomerTwo(htRegions Alg, string fname, string lname, long long int bankAccount, int numMemb, int *ages, string region, string city, string district, long long int id)
{ // same function as the previous , but this is used when inserting our dataset chosen to avoid show CustomerIds each time when inserting the customers at the beginning of the program
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, ages, region, city, district, id);
    long long int NewID = cus->ElectricityAccountId;
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->insertNewCustomerBST(cus);
}

void setInfoOneMonth(htRegions &HReg, long long int ID, int month, int year, double Mconsumption, double Minjection)
{
    bool exists = false;
    Bill bill;                                  // create bill
    bill.setBillInfo(Mconsumption, Minjection); // set Bill info
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = HReg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->setInfoCustomerOneMonthBST(ID, month, year, bill, exists);
    if (exists == true) // if customer exist then passing the appropriate needed values to department to calculate its profit each time setting the bills of any customer belongs to,to avoid searching each time for the paiments of all customers
    {
        double difference = 5 * Mconsumption - 3 * Minjection;
        Cptr->setInfoDepartment(month, year, difference, Minjection);
    }
}

void getOnemonthBill(htRegions &Alg, long long int ID, int month, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    Customers *B = Cptr->Districts->getBST(D);
    B->getOneMonthBillBST(ID, month, year);
}

void getOneYearBill(htRegions Alg, long long int ID, int year)
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

void getPeriodBill(htRegions &Alg, long long int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
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

void readCustomersFile(htRegions &Alg)
{
    ifstream file("Customers.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return;
    }

    while (getline(file, line))
    {
        istringstream lineStream(line);
        IDSorNames.clear();

        while (getline(lineStream, IDorName, ','))
        {
            IDSorNames.push_back(IDorName);
        }

        if (IDSorNames.size() >= 10)
        {
            int ages[IDSorNames.size() - 9];
            for (int i = 0; i < IDSorNames.size() - 9; i++)
            {
                ages[i] = stoi(IDSorNames[9 + i]);
            }
            insertNewCustomer(Alg, IDSorNames[0], IDSorNames[1], stoi(IDSorNames[2]), stoi(IDSorNames[3]), ages, IDSorNames[4], IDSorNames[5], IDSorNames[6], stoll(IDSorNames[7]));
        }
    }
}

void FillHashTablesRCD(htRegions &Reg, DepartmentHeap &heap)
{
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

            Reg.insertRegion(Region(RegionID, regionName));
            Reg.insertCity(RegionID, City(CityID, cityName), heap);
            Reg.insertDistrict(RegionID, CityID, District(DistrictID, districtName));
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << endl;
    }
}

void SetCustomersFromFile(htRegions &Reg)
{
    int ages1[] = {48};
    insertNewCustomerTwo(Reg, "Nouha", "Mouchaal", 8300820588, 1, ages1, "Adrar", "Adrar", "Adrar", 869798390);
    int ages2[] = {41};
    insertNewCustomerTwo(Reg, "Yusuf", "Mokhtari", 4640001367, 1, ages2, "Khenchela", "Bouhmama", "Yabous", 352429046);
    int ages3[] = {76, 34, 83, 54, 58};
    insertNewCustomerTwo(Reg, "Amani", "Lekhdari", 5083422879, 5, ages3, "Adrar", "Adrar", "Adrar", 542942942);
    int ages4[] = {4};
    insertNewCustomerTwo(Reg, "Khalid", "Achouri", 6094870317, 1, ages4, "Souk_Ahras", "Haddada", "Ouled_Moumen", 107561686);
    int ages5[] = {58};
    insertNewCustomerTwo(Reg, "Yousuf", "Lassouioui", 5020364384, 1, ages5, "Souk_Ahras", "Haddada", "Ouled_Moumen", 550932742);
    int ages6[] = {36, 36, 45, 58, 18};
    insertNewCustomerTwo(Reg, "Wissam", "Saidi", 1399874991, 6, ages6, "Tipaza", "Gouraya", "Gouraya", 499271108);
    int ages7[] = {82, 74, 81, 73, 35, 5};
    insertNewCustomerTwo(Reg, "Mustafa", "Gourab", 6067171954, 7, ages7, "Tipaza", "Gouraya", "Gouraya", 826830325);
    int ages8[] = {26, 5, 63, 69};
    insertNewCustomerTwo(Reg, "Djamel", "Sasi", 6400266291, 5, ages8, "Tipaza", "Gouraya", "Gouraya", 506801070);

    int ages9[] = {27, 59};
    insertNewCustomerTwo(Reg, "Bilal", "Benzaoui", 6360360548, 2, ages9, "Tipaza", "Gouraya", "Gouraya", 824549593);

    int ages10[] = {16, 31, 32, 60};
    insertNewCustomerTwo(Reg, "Amir", "Lassouioui", 6148822254, 4, ages10, "Adrar", "Adrar", "Bouda", 123407668);

    setInfoOneMonth(Reg, 101001869798390, 11, 2023, 45, 24);
    setInfoOneMonth(Reg, 101001869798390, 7,2023,167,12);
    setInfoOneMonth(Reg, 101001869798390, 3,2023,60,27);
    setInfoOneMonth(Reg, 101001869798390, 1,2023,55,0);
    setInfoOneMonth(Reg, 101001869798390, 9,2023,29,21);
    setInfoOneMonth(Reg, 4003458352429046, 7,2023,166,20);
    setInfoOneMonth(Reg, 4003458352429046, 5,2023,67,22);
    setInfoOneMonth(Reg, 4003458352429046, 8,2023,132,17);
    setInfoOneMonth(Reg, 101001542942942 , 11,2023,47,9);
    setInfoOneMonth(Reg, 101001542942942 , 5,2023,107,28);
    setInfoOneMonth(Reg, 101001542942942 , 11, 2023, 45, 24);
    setInfoOneMonth(Reg, 4003458352429046, 8,2023,161,7);
    setInfoOneMonth(Reg, 4003458352429046, 5,2023,107,28);
    setInfoOneMonth(Reg, 4003458352429046, 11, 2023, 45, 24);
    setInfoOneMonth(Reg, 4102512107561686, 8,2023,4,200);
    setInfoOneMonth(Reg, 4102512107561686, 9,2023,149,26);
    setInfoOneMonth(Reg, 4102512107561686,7, 2023,158,2);
    
}
#endif