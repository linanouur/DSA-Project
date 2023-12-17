#ifndef REGION_H
#define REGION_H
#include"City.h"
#include<iostream>
#include<string>
using namespace std;
const int num_reg = 100;

// class City;
// class htCities;

class Region {
public:
    int RegionID;
    string RegionName;
    htCities* Cities;  
    Region();
    Region(int id, const string& name);  
    
    Region& operator = (const Region& region) {
        RegionID = region.RegionID;
        RegionName = region.RegionName;
        Cities = region.Cities;
        return *this;
    }
    
};

class htRegions {
public:
    Region regions[num_reg];
    int hashFunctionRegion(int key);
    void insertRegion(const Region& region);
    Region* getRegion(int RegionID);
    void insertCity(int RegionID, const City& city);   
    void displaycities(int RegionID);
   


};

#endif 
