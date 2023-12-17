#ifndef NEWRCD_CPP 
#define NEWRCD_CPP
 
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
        districtMap[districtID].insertNewCustomerBST(ptr);
    }

    void displayCustomers(int districtID)
    {
        std::cout << "Customers in District " << districtID << ": ";
        districtMap[districtID].printLevelOrder();
    }

    void setInfoMonthCustomerDistrict(int districtID, int ID, int month, int year, Bill &other)
    {
        districtMap[districtID].setInfoCustomerOneMonthBST(ID, month, year, other);
    }

    void getOnemonthBillD(int districtID, int ID, int month, int year)
    {
        districtMap[districtID].getOneMonthBillBST(ID, month, year);
    }

    void getOneYearBillD(int districtID, int ID, int year)
    {
        districtMap[districtID].getOneYearBillBST(ID, year);
    }

    void getOnePeriodBillD(int districtID, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
    {
        districtMap[districtID].getPeriodBillBST(ID, monthStart, monthEnd, yearStart, yearEnd);
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

    void addCustomerToCity(int cityID, int districtID, Customer *ptr)
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
            district.printLevelOrder(); 
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

     void displayDistricts(int cityID) { 
        cout<<"Districts in region"<<cityID<<endl; 
        for(auto &[districtID,district] : cityMap[cityID].districtMap) 
        { 
            cout<<districtID; 
        }
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

    void addCustomerToRegion(int regionID, int cityID, int districtID, Customer *ptr)
    {
        regionMap[regionID].addCustomerToCity(cityID, districtID, ptr);
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
    void displaycities(int regionID) { 
        cout<<"cities in region"<<regionID<<endl; 
        for(auto &[cityID,City]: regionMap[regionID].cityMap) 
        { 
            cout<<cityID; 
            // cityMap[].displayDistricts(cityID);
        }
    }
};


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


void insertNewCustomer(RegionHashTable alg , string fname, string lname, int bankAccount, int numMemb, string region, string city, string district ,int id){
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, region, city, district, id);
    long int NewID = cus->generateCustomerID(region,city,district,id);
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID);
    alg.addCustomerToRegion(R,C,D,cus);
}



void setInfoOneMonth(RegionHashTable Alg ,int ID , int month , int year , int Mconsumption , int Minjection){
    Bill bill;
    bill.setBillInfo(Mconsumption,Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.setInfoMonthCustomerRegion(R , C , D, ID, month, year, bill);
}

void getOnemonthBill(RegionHashTable Alg ,int ID, int month, int year){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.getOnemonthBillR(R , C , D, ID, month, year);
}

void getOneYearBill(RegionHashTable Alg , int ID , int year){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.getOneYearBillR(R , C , D, ID, year);
}

void getPeriodBill( RegionHashTable &Alg , int ID , int monthStart, int monthEnd, int yearStart, int yearEnd){
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Alg.getOnePeriodBillR(R , C , D, ID, monthStart, monthEnd , yearStart , yearEnd);
}


int main() {
    RegionHashTable Alg;
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
            Alg.displaycities(2);
        }
        file.close();

    } else {
        cout << "Unable to open file." << endl;
    }

 int number=12222;
    std::cout << "Number with leading zero: " <<setw(5)<< setfill('0') << number << std::endl;
    return 0;
}  
#endif
