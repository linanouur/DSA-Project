#ifndef REGION_H
#define REGION_H 
#include<iostream>
#include<string>
#include"City.h" 
#include"District.h"

using namespace std;
const int num_reg = 100;

// class City;
 class htCities;
class htcities; 
class Region {
public:
    int RegionID;
    string RegionName;
    htCities* Cities;  
    Region();
    Region(int id, const string& name);  
    
   
};

class htRegions {
public:
    Region regions[num_reg];
    int hashFunctionRegion(int key);
    void insertRegion(const Region& region);   
    Region* getRegion(int RegionID);
    void displaycities(int RegionID);
   


};

#endif 
