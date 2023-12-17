#ifndef DISTRICT_H
#define DISTRICT_H

#include"City.h"
#include<iostream>
#include<string>

const int num_dis = 100;
class City;
class District {
public:
    int district_id;
    std::string district_name;

    District();
    District(int id, const std::string& name);
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
