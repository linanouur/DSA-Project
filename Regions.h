#ifndef REGION_H
#define REGION_H

#include<iostream>
#include<string>
#include"City.h"
#include"District.h"
#include"customers.h"

using namespace std;

enum class value
{
    empty,
    inserted
};

const int num_reg = 100;


class Region {
public:
    int RegionID;
    string RegionName;
    htCities* Cities;  
    value cas = value::empty;

    Region();
    Region(int id, const string& name);    
};

class htRegions {
public:
    Region regions[num_reg];
    int hashFunctionRegion(int key);
    void insertRegion(const Region& region);   
    void insertCity(int regionID , const City &city);
    void insertDistrict(int regionID , int cityID , const District &district);
    Region* getRegion(int RegionID);
    void displaycities(int RegionID);

};

#endif 
