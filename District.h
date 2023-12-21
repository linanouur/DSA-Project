#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
#include <string>
#include "customers.h"

using namespace std;

const int num_dis = 100;
// class City;

class District
{
public:
    int DistrictID;
    string DistrictName;
    Customers BST;
    District();
    District(int id, const std::string &name);
    Customer *searchinDistrict( int ID)
    {
        return BST.searchCustomer(ID);
    }
};

class htDistricts
{
public:
    District districts[num_dis];
    int hashFunctionDistrict(int key);
    void insertDistrict(const District &district);
    void insertDistrictinCity(int cityId, const District &district);
    District getDistrict(int districtId);
    District *getDistrictptr(int districtId);
    Customers *getBST(int districtID){
        return &districts[districtID].BST;
    }
    
    void insertCustomerIntoDistrict(District &obj, Customer *node)
    {
        obj.BST.insertNewCustomerBST(node);
    }

    void setInfoInDistrict(District &obj, int ID, int month, int year, Bill &b)
    {
        cout << obj.DistrictName << endl;
        obj.BST.setInfoCustomerOneMonthBST(ID, month, year, b);
    }

void displayAllDistricts(){
        for (int i = 0; i < num_dis; i++)
    {
         if (districts[i].DistrictID != 0){
        std::cout<<districts[i].DistrictName << "  " << districts[i].DistrictID << endl;
        
    }
    }
    }

//    Customer *searchCustomerinHD(int DistrictID, int ID)
//     {
//         District *district = getDistrictptr(DistrictID);
//         if (district != nullptr)
//         {
//             return district->searchinDistrict(ID);
//         }
//         return nullptr; // District not found
//     }
};

#endif
