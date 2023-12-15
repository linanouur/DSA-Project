#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP


#include <iostream>
#include<string>
#include "customer.h"
#include "calendar.cpp"
#include "bills.cpp" 
#include <fstream>
#include <sstream>
#include <vector> 
#include <iomanip>
#include"userFunctions.cpp"
using namespace std;






void Customer ::settotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

 long int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{

    setInfo(fname, lname, bankAccount, numMemb, region, city, district);
   ElectricityAccountId= generateCustomerID(region, city, district);
   
  
 
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
    if (IDs[0].length() == 1) {
    string idd= IDs[0];
     string  IDRegionstring =string(2 - IDs[0].length(), '0') + idd ; 
    IDs[0]=IDRegionstring;
     } 
    concatenatedIDs = IDs[0] + IDs[1] + IDs[2];

    return concatenatedIDs;
}
 long int Customer ::generateCustomerID(string region, string city, string district)
{
    static int CustomerIDS = 1; 
    
    string concatenatedIDs = getConcatenatedIDs(region, city, district);  
     string CustomerIDstring = to_string(CustomerIDS);
     string  IDstring =string(4 - CustomerIDstring.length(), '0') + CustomerIDstring ;
    string CustomerID = concatenatedIDs + IDstring;
    CustomerIDS++;

    return stoi(CustomerID);
}





#endif
