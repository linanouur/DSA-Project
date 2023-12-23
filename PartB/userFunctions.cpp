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
#include "customer.h"
#include "customer.cpp" 
#include "customersAVL.h"
#include "customersAVL.cpp"
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
// #include "weather.cpp"
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
        return-1;
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
            IDSorNames[1] == region )
        {
             
              return stoi(IDSorNames[0]);    
           
           

        }
    }

    return -1;
} 
int getCityIDfromFile( string city)
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

        if (IDSorNames.size() >= 6 && IDSorNames[3] == city )
        {
               
                 return stoi (IDSorNames[2]); 
      
        }
    }

    return-1;
}  
int getDistrictIDfromFile( string district)
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

        if (IDSorNames.size() >= 6 && IDSorNames[5] == district )
        {
          return stoi(IDSorNames[4]); 
        }
    }

    return-1;
} 


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

void insertNewCustomer(htRegions Alg, string fname, string lname, int bankAccount, int numMemb, vector<int> ages, string region, string city, string district, int id)
{
    Customer *cus = new Customer(fname, lname, bankAccount, numMemb, ages, region, city, district, id);
    long int NewID = cus->ElectricityAccountId;
    int R = getRegionId(NewID);
    int C = getCityId(NewID);
    int D = getDistrictId(NewID); 
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    CustomersAVL *A = Cptr->Districts->getAVL(D);
    A->insertNewCustomerAVL(cus);
   
}

void setInfoOneMonth(htRegions Alg, int ID, int month, int year, int Mconsumption, int Minjection)
{
    Bill bill;
    bill.setBillInfo(Mconsumption, Minjection);
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    int difference = 5 * bill.MonthConsumptionAmount - 3 * bill.MonthInjectionAmount;
    cout<<"VALUE A:"<<Minjection<<endl;
    Cptr->setInfoDepartment(month, year, difference, Minjection);
    District Dis = Cptr->Districts->getDistrict(D);
    CustomersAVL *A = Cptr->Districts->getAVL(D);
    A->setInfoCustomerOneMonthAVL(ID, month, year, bill);
}

void getOnemonthBill(htRegions Alg, int ID, int month, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    CustomersAVL *A = Cptr->Districts->getAVL(D);
    A->getOneMonthBillAVL(ID, month, year);
}

void getOneYearBill(htRegions Alg, int ID, int year)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    CustomersAVL *A = Cptr->Districts->getAVL(D);
    A->getOneYearBillAVL(ID, year);
}

void getPeriodBill(htRegions &Alg, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    int R = getRegionId(ID);
    int C = getCityId(ID);
    int D = getDistrictId(ID);
    Region *Rptr = Alg.getRegion(R);
    City *Cptr = Rptr->Cities->getCityptr(C);
    District Dis = Cptr->Districts->getDistrict(D);
    CustomersAVL *A = Cptr->Districts->getAVL(D);
    A->getPeriodBillAVL(ID, monthStart, monthEnd, yearStart, yearEnd);
}

void getOneMonthBillCountry(htRegions &Alg, int month, int year)
{
    Alg.getOneMonthBillinRegions(month, year);
}

void getOneMonthBillRegion(htRegions &Alg, int RegionID, int month, int year)
{
    Region *R = Alg.getRegion(RegionID);
    R->getOneMonthBillinRegion(month, year);
}

void getOneMonthBillCity(htRegions &Alg, int RegionID, int CityID, int month, int year)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getOneMonthBillinCity(month, year);
}

void getOneMonthBillDistrict(htRegions &Alg, int RegionID, int CityID, int DistrictID, int month, int year)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getOneMonthBillinDistrict(month, year);
}

void getOneYearBillCountry(htRegions &Alg, int year)
{
    Alg.getOneYearBillinRegions(year);
}

void getOneYearRegion(htRegions &Alg, int RegionID, int year)
{
    Region *R = Alg.getRegion(RegionID);
    R->getOneYearBillinRegion(year);
}

void getOneYearBillCity(htRegions &Alg, int RegionID, int CityID, int year)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getOneYearBillinCity(year);
}

void getOneYearBillDistrict(htRegions &Alg, int RegionID, int CityID, int DistrictID, int year)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getOneYearBillinDistrict(year);
}

void getOnePeriodBillCountry(htRegions &Alg, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    Alg.getPeriodBillinRegions(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodRegion(htRegions &Alg, int RegionID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    Region *R = Alg.getRegion(RegionID);
    R->getPeriodBillinRegion(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodBillCity(htRegions &Alg, int RegionID, int CityID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    C->getPeriodBillinCity(monthStart, monthEnd, yearStart, yearEnd);
}

void getOnePeriodBillDistrict(htRegions &Alg, int RegionID, int CityID, int DistrictID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    Region *R = Alg.getRegion(RegionID);
    City *C = R->Cities->getCityptr(CityID);
    District D = C->Districts->getDistrict(DistrictID);
    D.getPeriodBillinDistrict(monthStart, monthEnd, yearStart, yearEnd);
}
/*
int main()
{
 
    htRegions regionHashTable;
    DepartmentHeap depHeap;
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
            regionHashTable.insertCity(RegionID, City(CityID, cityName), depHeap);
            regionHashTable.insertDistrict(RegionID, CityID, District(DistrictID, districtName));
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << endl;
    }

    ifstream fileTwo("CustomerInfo.csv");

    // if (fileTwo.is_open())
    // {
    //     int id=1;
    //     string line;
    //     while (getline(fileTwo, line))
    //     {
    //         stringstream ss(line);
    //         string fname, lname, bankAccount, numMemb, ages, region, city, district;
    //         vector<int> A;
    //         getline(ss, fname, ',');
    //         getline(ss, lname, ',');
    //         getline(ss, region, ',');
    //         getline(ss, city, ',');
    //         getline(ss, district, ',');
    //         getline(ss, numMemb, ',');

    //         int num = stoi(numMemb);
    //         for (int i = 0; i < num; i++)
    //         {
    //             string age;
    //             getline(ss, age, ',');
    //             A[i] = stoi(age);
    //         }

    //         getline(ss, bankAccount, ',');
    //         int Account = stoi(bankAccount);
    //         // getline(ss, id, ',');
    //         // int ID = stoi(id);

    //         insertNewCustomer(regionHashTable, fname, lname, Account, num, A, region, city, district, id);
    //         id=id+1;
    //     }

    //     fileTwo.close();
    // }
    // else
    // {
    //     std::cout << "Unable to open file." << endl;
    // }

    vector<int> A = {1, 2, 3, 4};

    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 123456, 5, A, "Adrar", "Adrar", "Adrar", 12);
    insertNewCustomer(regionHashTable, "Moh", "Ali", 1236, 5, A, "Adrar", "Adrar", "Adrar", 13);
    insertNewCustomer(regionHashTable, "Mo", "Ali", 13456, 5, A, "Adrar", "Adrar", "Adrar", 14);
    insertNewCustomer(regionHashTable, "Ahmed", "Ali", 1256, 5, A, "Adrar", "Adrar", "Adrar", 15);
    insertNewCustomer(regionHashTable, "Moha", "Ali", 123456, 5, A, "Adrar", "Adrar", "Adrar", 16);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1236, 5, A, "Adrar", "Adrar", "Adrar", 17);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 13456, 5, A, "Adrar", "Adrar", "Adrar", 18);
    insertNewCustomer(regionHashTable, "Mohamed", "Ali", 1256, 5, A, "Adrar", "Adrar", "Adrar", 19);
     
     Region *Rptr = regionHashTable.getRegion(1);
     City *Cptr = Rptr->Cities->getCityptr(1);
     District D = Cptr->Districts->getDistrict(1); 
      D.AVL.printLevelOrder(); 
    setInfoOneMonth(regionHashTable, 1010010014, 1, 2023, 100, 100); 
    setInfoOneMonth(regionHashTable, 1010010015, 1, 2023, 100, 100);
    setInfoOneMonth(regionHashTable, 1010010016, 1, 2023, 100, 100); 
    getOnemonthBill(regionHashTable, 1010010014, 1, 2023);
    getOnemonthBill(regionHashTable, 1010010015, 1, 2023);
    getOnemonthBill(regionHashTable, 1010010016, 1, 2023);
    
    D.AVL.displayOneMonthBillsALLPub(1, 2023);

    

    // cout << D.DistrictName << endl;
    // District Dis = Cptr->Districts->getDistrict(1);
    // Dis.BST.print();
    // std::cout << "mmmmmm" << endl;
    // Customer *nas = D.searchinDistrict(1010010002);
    // if(nas==nullptr) cout<<"null"<<endl;
    // else cout << nas->FamilyName << endl;

 
  
    
    // B->displayOneMonthBillsALLPub(1, 2023);
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
} */
#endif