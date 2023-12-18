#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include<iostream>
#include<string>
#include"customer.h"
#include"calendar.cpp"
#include "bills.cpp" 
#include "bills.h"
#include <fstream>
#include <sstream>
#include <vector> 
#include <iomanip> 

#include"userFunctions.cpp"
using namespace std;


void Customer::settotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

 long int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district, int id )
{

    setInfo(fname, lname, bankAccount, numMemb,region, city, district);
    ElectricityAccountId = generateCustomerID(region, city , district,id);
}

void Customer::setInfo(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
   
    Region = region;
    City = city;
    District = district;
    haveInjectedBefore = false;
    left = nullptr;
    right = nullptr;
    vector<string> IDs = getIDs(Region, City, District);
}


vector<string> Customer ::getIDs(string region, string city, string district)
{
    ifstream file("RegionCityDistrict.csv");
    string line;
    string IDorName;
    vector<string> IDSorNames;

    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return vector<string>(3, "");
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
            IDSorNames[1] == region &&
            IDSorNames[3] == city &&
            IDSorNames[5] == district)
        {
            return vector<string>{IDSorNames[0], IDSorNames[2], IDSorNames[4]};
        }
    }

    return vector<string>(3, "");
}


string Customer ::getConcatenatedIDs(string region, string city, string district)
{
    vector<string> IDs = getIDs(region, city, district);
    string concatenatedIDs = ""; 
   
    concatenatedIDs = IDs[0] + IDs[1] + IDs[2];

    return concatenatedIDs;
}
 long int Customer ::generateCustomerID(string region, string city, string district, int CustomerID)
{
   if(CustomerID>0 && CustomerID<10000) { 
    string concatenatedIDs = getConcatenatedIDs(region, city, district);  
     string CustomerIDstring = to_string(CustomerID);
     string  IDstring =string(4 - CustomerIDstring.length(), '0') + CustomerIDstring ;
    string CustomerID = concatenatedIDs + IDstring;
    return stoi(CustomerID);
   } 
   else { 
    cout<<"Invalid Customer ID"<<endl; 
    return -1; 
   } 

}

void Customer :: getOneMonthBillCustomer(int month, int year){
cout << "Customer: " << firstName << " " << FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;
 Year &y = Customeryears->getYear(year);
        Bill &m = y.yearMonths->getbill(month);
        m.displayBill();
}


void Customer :: getOneYearBillCustomer(int year){
    cout << "Customer: " << firstName << " " << FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;
    Year &y = Customeryears->getYear(year);
        for (int month = 1; month < 13; month++)
        {
            Bill &m = y.yearMonths->getbill(month);
            cout << "Month " << month << endl;
            m.displayBill();
        }
}


void Customer :: getPeriodBillCustomer( int monthStart, int monthEnd, int yearStart, int yearEnd){
    cout << "Customer: " << firstName << " " <<FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;
if (yearStart == yearEnd)
        {
            Year &y = Customeryears->getYear(yearStart);
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
            Year &y = Customeryears->getYear(year);
            for (int month = 1; month < 13; month++)
            {
                if (year = yearEnd && month > monthEnd)
                    break;
                Bill &m = y.yearMonths->getbill(month);
                m.displayBill();
            }
        }
 }

#endif
