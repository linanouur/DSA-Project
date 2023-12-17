#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include "customer.cpp"
#include "customers.cpp"
using namespace std;

// DistrictHashTable class storing a hash table for each district containing a CustomerBST

RegionHashTable Alg;
class DistrictHashTable
{

public:
    unordered_map<int, Customers> districtMap;
    void addDistrict(int districtID)
    {
        districtMap[districtID] = Customers();
    }

    void addCustomer(int districtID, Customer *ptr)
    {
        districtMap[districtID].insertNewCustomer(ptr);
    }

    void displayCustomers(int districtID)
    {
        std::cout << "Customers in District " << districtID << ": ";
        districtMap[districtID].printLevelOrder();
    }

    void setInfoMonthCustomerDistrict(int districtID, int ID, int month, int year, Bill &other)
    {
        districtMap[districtID].setInfoCustomerOneMonth(ID, month, year, other);
    }

    void getOnemonthBillD(int districtID, int ID, int month, int year)
    {
        districtMap[districtID].getOneMonthBill(ID, month, year);
    }

    void getOneYearBillD(int districtID, int ID, int year)
    {
        districtMap[districtID].getOneYearBill(ID, year);
    }

    void getOnePeriodBillD(int districtID, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
    {
        districtMap[districtID].getPeriodBill(ID, monthStart, monthEnd, yearStart, yearEnd);
    }
};

// CityHashTable class storing a hash table for each city containing a DistrictHashTable
class CityHashTable
{

public:
    unordered_map<int, DistrictHashTable> cityMap;
    void addCity(int cityID)
    {
        cityMap[cityID] = DistrictHashTable();
    }

    void addDistrict(int cityID, int districtID)
    {
        cityMap[cityID].addDistrict(districtID);
    }

    void addCustomerToDistrict(int cityID, int districtID, Customer *ptr)
    {
        cityMap[cityID].addCustomer(districtID, ptr);
    }

    void displayCustomersInDistrict(int cityID, int districtID)
    {
        cityMap[cityID].displayCustomers(districtID);
    }
    void displayCustomersInCity(int cityID)
    {
        cout << "Customers in City " << cityID << ":" << endl;
        for (auto &[districtID, district] : cityMap[cityID].districtMap)
        {
            district.printLevelOrder(); // Assuming CustomerBST has a displayCustomers() method
        }
    }

    void setInfoMonthCustomerCity(int cityID, int districtID, int ID, int month, int year, Bill &other)
    {
        cityMap[cityID].setInfoMonthCustomerDistrict(districtID, ID, month, year, other);
    }

    void getOnemonthBillC(int cityID, int districtID, int ID, int month, int year)
    {
        cityMap[cityID].getOnemonthBillD(districtID, ID, month, year);
    }

    void getOneYearBillC(int cityID, int districtID, int ID, int year)
    {
        cityMap[cityID].getOneYearBillD(districtID, ID, year);
    }

    void getOnePeriodBillC(int cityID, int districtID, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
    {
        cityMap[cityID].getOnePeriodBillD(districtID, ID, monthStart, monthEnd, yearStart, yearEnd);
    }
};

// RegionHashTable class storing a hash table for each region containing a CityHashTable

class RegionHashTable
{
public:
    unordered_map<int, CityHashTable> regionMap;

    void addRegion(int regionID)
    {
        regionMap[regionID] = CityHashTable();
    }

    void addCity(int regionID, int cityID)
    {
        regionMap[regionID].addCity(cityID);
    }

    void addDistrictToCity(int regionID, int cityID, int districtID)
    {
        regionMap[regionID].addDistrict(cityID, districtID);
    }

    void addCustomerToDistrict(int regionID, int cityID, int districtID, Customer *ptr)
    {
        regionMap[regionID].addCustomerToDistrict(cityID, districtID, ptr);
    }

    void displayCustomersInDistrict(int regionID, int cityID, int districtID)
    {
        regionMap[regionID].displayCustomersInDistrict(cityID, districtID);
    }
    void displayCustomersInCity(int regionID, int cityID)
    {
        regionMap[regionID].displayCustomersInCity(cityID);
    }

    void setInfoMonthCustomerRegion(int regionID, int cityID, int districtID, int ID, int month, int year, Bill &other)
    {
        regionMap[regionID].setInfoMonthCustomerCity(cityID, districtID, ID, month, year, other);
    }

    void getOnemonthBillR(int regionID, int cityID, int districtID, int ID, int month, int year)
    {
        regionMap[regionID].getOnemonthBillC(cityID, districtID, ID, month, year);
    }

    void getOneYearBillR(int regionID, int cityID, int districtID, int ID, int year)
    {
        regionMap[regionID].getOneYearBillC(cityID, districtID, ID, year);
    }

    void getOnePeriodBillR(int regionID, int cityID, int districtID, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
    {
        regionMap[cityID].getOnePeriodBillC(cityID, districtID, ID, monthStart, monthEnd, yearStart, yearEnd);
    }
};

int main() {
    
    ifstream file("RegionCityDistrict.csv"); // Update the file path accordingly

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
            Alg.addRegion(RegionID);
            Alg.addCity(RegionID, CityID);
            Alg.addDistrictToCity(RegionID, CityID, DistrictID);
        }
        file.close();

    } else {
        cout << "Unable to open file." << endl;
    }

 int number=12222;
    std::cout << "Number with leading zero: " <<setw(5)<< setfill('0') << number << std::endl;
    return 0;
}
