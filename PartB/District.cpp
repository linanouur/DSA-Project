#ifndef DISTRICT_CPP
#define DISTRICT_CPP

#include <iostream>
#include <string>
#include "District.h"
#include "customersAVL.h"
#include "customersAVL.cpp"

using namespace std;

District::District() : DistrictID(0), DistrictName("")
{
    // BST= new Customers();
}

District::District(int id, const std::string &name) : DistrictID(id), DistrictName(name) {}
void District::getOneMonthBillinDistrict(int month, int year)
{
    AVL.displayOneMonthBillsALLPub(month, year);
}
void District ::getPeriodBillinDistrict(int StartMonth, int StartYear, int EndMonth, int EnDYear)
{
    AVL.displayOnePeriodBillsALLPub(StartMonth, StartYear, EndMonth, EnDYear);
}
void District ::getOneYearBillinDistrict(int year)
{
    AVL.displayOneYearBillsALLPub(year);
}

int htDistricts::hashFunctionDistrict(int key)
{
    return key % num_dis;
}

void htDistricts::insertDistrict(const District &district)
{
    int index = hashFunctionDistrict(district.DistrictID);
    if (districts[index].DistrictID == 0)
    {
        districts[index] = district;
    }
}

District htDistricts::getDistrict(int districtId)
{
    int index = hashFunctionDistrict(districtId);
    return districts[index];
}

District *htDistricts::getDistrictptr(int districtId)
{
    int index = hashFunctionDistrict(districtId);
    return &districts[index];
}

void htDistricts ::insertCustomerIntoDistrict(District &obj, Customer *node)
{
    obj.AVL.insertNewCustomerAVL(node);
}



void htDistricts::displayAllDistricts()
{
    for (int i = 0; i < num_dis; i++)
    {
        if (districts[i].DistrictID != 0)
        {
            std::cout << districts[i].DistrictName << "  " << districts[i].DistrictID << endl;
        }
    }
}

CustomersAVL *htDistricts ::getAVL(int districtID)
{
    return &districts[districtID].AVL;
}


#endif