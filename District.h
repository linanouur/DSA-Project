#ifndef DISTRICT_H
#define DISTRICT_H

#include"City.h"
#include<iostream>
#include<string>
using namespace std ; 
#include "customers.h"
const int num_dis = 100;
class City;
class District {
public:
    int DistrictID;
    string DistrictName;

    District();
    District(int id, const std::string& name); 
    District operator = (const District& district) {
        DistrictID = district.DistrictID;
        DistrictName = district.DistrictName;
        return *this;
    } 
    Customers *CustomerBST; 
};

class htDistricts {
public:
    District districts[num_dis];
    int hashFunctionDistrict(int key);
    void insertDistrict(const District& district);
    City* getCity (int cityId);
    District* getDistrict(int districtId);
    void insertDistrict(int cityId, const District& district);  
    

};

#endif 
