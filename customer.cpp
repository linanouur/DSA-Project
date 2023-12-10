#include <iostream>
#include<string>
#include "Customer.h"
#include "calendar.cpp"
#include "bills.cpp" 
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


void Customer ::settotalInjection(int value)
{
    totalInjection = totalInjection + value;
}

int Customer ::getCustomerId()
{
    return ElectricityAccountId;
}

Customer::Customer(string fname, string lname, int bankAccount, int numMemb, string region, string city, string district)
{

    setInfo(fname, lname, bankAccount, numMemb, region, city, district);
    ElectricityAccountId = generateCustomerID();
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
int Customer ::generateCustomerID()
{
    static int CustomerIDS = 1;
    string concatenatedIDs = getConcatenatedIDs(Region, City, District);
    string CustomerID = concatenatedIDs + to_string(CustomerIDS);
    CustomerIDS++;

    return stoi(CustomerID);
}

int main()
{
    Customers BST;
    BST.insertNewCustomer("John", "Doe", 12345, 3, "North", "Mahelma", "Bouira");
    BST.insertNewCustomer("Jane", "Doe", 67890, 1, "South", "Algiers", "Bab El Oued");
    BST.insertNewCustomer("Michael", "Smith", 45678, 4, "East", "Constantine", "Salah Bey");
    BST.insertNewCustomer("Emma", "Brown", 23456, 2, "West", "Oran", "Es Senia");
    BST.insertNewCustomer("David", "Miller", 89012, 5, "North", "Skikda", "El Harrouch");
    BST.insertNewCustomer("Aisha", "Boudjemaa", 76543, 2, "South", "Tlemcen", "Nedroma");
    BST.insertNewCustomer("Karim", "Belkacem", 34567, 4, "East", "Batna", "Merouana");
    BST.insertNewCustomer("Fatima", "Zohra", 12345, 1, "West", "Annaba", "El Bouni");
    BST.print(); // Outputs the ElectricityAccountId values of the customers
    cout << endl;

    cout << "enter customer id" << endl;
    int id;
    cin >> id;
    cout << getRegionId(id) << endl;
    cout << getCityId(id) << endl;
    cout << getDistrictId(id) << endl;
    cout << getCustomerID(id) << endl;

    Customer *cust = BST.searchCustomer(67890);
    if (cust != nullptr)
    {
        cust->Customeryears->insertYear(1950);
        Year &y = cust->Customeryears->getYear(1950);
        Bill &m = y.yearMonths->getbill(3);
        cout << "Month number: " << m.numberMonth << endl;
    }
    else
    {
        cout << "Customer not found." << endl;
    }
    return 0;
}

int getPrize(Customers *BST)
{
    cout << "The winner ID: ";
    return BST->getmaxInjectorID();
}
