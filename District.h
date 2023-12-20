#ifndef DISTRICT_H
#define DISTRICT_H


#include <iostream>
#include <string>
#include"customers.h"
#include"customers.cpp"
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
   
   
};

class htDistricts  {
public:
    District districts[num_dis];
    int hashFunctionDistrict(int key);
    void insertDistrict(const District& district); 
    void insertDistrictinCity(int cityId, const District& district);  
    District* getDistrict(int districtId);
    void insertDistrict(int cityId, const District& district);  
    

};

#endif
