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
    bool existCus=false ;
     BST.displayOneMonthBillsALLPub(month, year , existCus);
    if (existCus==false) cout<<"No customers in district: "<<DistrictName<<endl;
   
}
void District ::getPeriodBillinDistrict(int StartMonth, int StartYear, int EndMonth, int EnDYear)
{
    bool existCus=false ;
    BST.displayOnePeriodBillsALLPub(StartMonth, StartYear, EndMonth, EnDYear,existCus);
      if (existCus==false) cout<<"No customers in district: "<< DistrictName<<endl;
}
void District ::getOneYearBillinDistrict(int year)
{
    bool existCus=false ;
    BST.displayOneYearBillsALLPub(year,existCus);
      if (existCus==false) cout<<"No customers in district: "<<DistrictName<<endl;
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
    obj.BST.insertNewCustomerBST(node);
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

Customers *htDistricts ::getBST(int districtID)
{
    return &districts[districtID].BST;
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