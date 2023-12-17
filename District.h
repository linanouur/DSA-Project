#ifndef DISTRICT_H
#define DISTRICT_H


#include <iostream>

#include"customers.h"
#include"customers.cpp"
#include <string>
using namespace std;

const int num_dis = 100;
// class City;
class District
{
public:
    int DistrictID;
    string DistrictName;
   Customers *BST;
    District();
    District(int id, const std::string &name);
    District operator=(const District &district)
    {
        DistrictID = district.DistrictID;
        DistrictName = district.DistrictName;
        return *this;
    }
};

class htDistricts
{
public:
    District districts[num_dis];
    int hashFunctionDistrict(int key);
    void insertDistrict(const District &district);
    District *getDistrict(int districtId);
   
  
};

#endif
