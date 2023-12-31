#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "customer.h"
#include "customers.h"
using namespace std;




Customer::Customer(string fname, string lname, long long int bankAccount, int numMemb, int *ages, string region, string city, string district, long long int id)
{
    Ages = new int[numMemb];
    setInfo(fname, lname, bankAccount, numMemb, ages, region, city, district);
    ElectricityAccountId = generateCustomerID(region, city, district, id); // generating Id for each customer
    Customeryears = new Years();
    for (int i = 2023; i < 2023 + 50; i++)
    {
        Customeryears->insertYear(i);
    }
    
}

void Customer::setInfo(string fname, string lname, long long int bankAccount, int numMemb, int *ages, string region, string city, string district)
{
    firstName = fname;
    FamilyName = lname;
    BankAccount = bankAccount;
    familyMembersNumber = numMemb;
    for (int i = 0; i < numMemb; i++)
    {
        Ages[i] = ages[i];
    }
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
long long int Customer ::generateCustomerID(string region, string city, string district, long int CustomerID)
{
    if (CustomerID > 0 && CustomerID < 1000000000)
    {
        string concatenatedIDs = getConcatenatedIDs(region, city, district);

        string CustomerIDstring = to_string(CustomerID);

        string Customerid = concatenatedIDs + CustomerIDstring;

        return stoll(Customerid);
    }
    else
    {
        cout << "Invalid Customer ID" << endl;
        return -1;
    }
}

void Customer::settotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

long long int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

void Customer ::getOneMonthBillCustomer(int month, int year)  
{
    cout << "Customer: " << firstName << " " << FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;  //printing some information about the customer
    Year *y = Customeryears->getYear(year);  //get the address of the year in the hashtable
    Bill *m = y->yearMonths->getbill(month); //get the address of the year in the hashtable
    cout << m->monthName <<" ";
    cout << y->year <<endl;
    m->displayBill(); //calling the appropriate bill display function
}

void Customer ::getOneYearBillCustomer(int year)
{
    cout << "Customer: " << firstName << " " << FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;
    Year *y = Customeryears->getYear(year);
    cout << y->year << endl;
    for (int month = 1; month < 13; month++)
    {
        Bill *m = y->yearMonths->getbill(month);
        cout << m->monthName << endl;
        m->displayBill();
    }
}

void Customer ::getPeriodBillCustomer(int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    cout << "Customer: " << firstName << " " << FamilyName << " , Electricity Account ID: " << ElectricityAccountId << endl;
    if (yearStart == yearEnd)  //both are the same so it should display months in the same year using a for loop
    {
        Year *y = Customeryears->getYear(yearStart);
        for (int month = monthStart; month < monthEnd; month++)
        {
            Bill *m = y->yearMonths->getbill(month);
            cout << m->monthName << " / " << y->year << endl;
            m->displayBill();
        }
        return;
    }

    for (int year = yearStart; year <= yearEnd; year++)   //a loop around the years of that period of time
    {
        Year *y = Customeryears->getYear(year);
        cout << y->year << endl;
        for (int month = 1; month < 13; month++)
        {
            if (year == yearStart && month < monthStart)
                break;
            if (year == yearEnd && month > monthEnd)
                break;
            Bill *m = y->yearMonths->getbill(month);
            cout << m->monthName << " / " << y->year << endl;
            m->displayBill();
        }
    }
}


#endif
