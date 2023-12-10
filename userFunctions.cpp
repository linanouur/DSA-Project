#ifndef USERFUNCTIONS_CPP
#define USERFUNCTIONS_CPP

#include <iostream>
#include <string>

using namespace std;


int getRegionId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string regionID = CustomerIDString.substr(0, 2);
    return stoi(regionID);
}
int getCityId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string cityID = CustomerIDString.substr(2, 2);
    return stoi(cityID);
}
int getDistrictId(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string districtID = CustomerIDString.substr(4, 2);
    return stoi(districtID);
}
int getCustomerID(int CustomerID)
{
    string CustomerIDString = to_string(CustomerID);
    string customerID = CustomerIDString.substr(6, CustomerIDString.length() - 6);
    return stoi(customerID);
}

void setInfoOneMonth(Customers *BST, int ID, int month, int year, int Mconsumption, int Minjection)
{
    Customer *cust = BST->searchCustomer(ID);
    cust->settotalInjection(Minjection);
    if (cust->totalInjection > BST->getmaxAmoutInjected())
        BST->setInfoNewInjector(ID, cust->totalInjection, cust->Region, cust->City, cust->District);
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        y.setYearlyTotal(Mconsumption * 5);
        y.setYearlyCredit(Minjection * 3);
        Bill &m = y.yearMonths->getbill(month);
        m.setBillInfo(Mconsumption, Minjection);
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void getOneMonthBill(Customers *BST, int ID, int month, int year)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << month
         << " / " << year << " : " << endl;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        Bill &m = y.yearMonths->getbill(month);
        m.displayBill();
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void getOneYearBill(Customers *BST, int ID, int year)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << year << " : " << endl;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        Year &y = cust->Customeryears->getYear(year);
        for (int month = 1; month < 13; month++)
        {
            Bill &m = y.yearMonths->getbill(month);
            cout << "Month " << month << endl;
            m.displayBill();
        }
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

void getPeriodBill(Customers *BST, int ID, int monthStart, int monthEnd, int yearStart, int yearEnd)
{
    // cout << "Region: " << Region << "  City: " << City << "  District: " << District << endl;
    cout << "Bill of " << monthStart << " / " << yearStart << " : "
         << "/t"
         << "To: " << monthEnd << " / " << yearEnd;
    Customer *cust = BST->searchCustomer(ID);
    cout << "Customer: " << cust->firstName << " " << cust->FamilyName << " , Electricity Account ID: " << cust->ElectricityAccountId << endl;
    if (cust != nullptr)
    {
        if (yearStart == yearEnd)
        {
            Year &y = cust->Customeryears->getYear(yearStart);
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
            Year &y = cust->Customeryears->getYear(year);
            for (int month = 1; month < 13; month++)
            {
                if (year = yearEnd && month > monthEnd)
                    break;
                Bill &m = y.yearMonths->getbill(month);
                m.displayBill();
            }
        }
    }
    else
    {
        cout << "Customer not found." << endl;
    }
}

#endif