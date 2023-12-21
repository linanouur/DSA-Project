#ifndef DISTRICT_CPP
#define DISTRICT_CPP

#include <iostream>
#include <string>
#include "District.h"
#include "customers.h"
#include "customers.cpp"

using namespace std;

District::District() : DistrictID(0), DistrictName("")
{
    // BST= new Customers();
}

District::District(int id, const std::string &name) : DistrictID(id), DistrictName(name) {}
void District::getOneMonthBillinDistrict(int month, int year)
{
    BST.displayOneMonthBillsALLPub(month, year);
}
void District ::getPeriodBillinDistrict(int StartMonth, int StartYear, int EndMonth, int EnDYear)
{
    BST.displayPeriodBillsALLPub(StartMonth, StartYear, EndMonth, EnDYear);
}
void District ::getOneYearBillinDistrict(int year)
{
    BST.displayOneYearBillsALLPub(year);
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

// void htDistricts::getOnemonthBillDistrict (int districtID, int month, int year)
// {
//     District *district = getDistrict(districtID);
//     if (district != nullptr)
//     {
//         district->BST->getOneMonthBillBST(districtID, month, year);

//       }
//     }

#endif