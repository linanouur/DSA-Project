#ifndef REGION_H
#define REGION_H
#include"City.h"
#include<iostream>
#include<string>

const int num_reg = 100;

class City;
class htCities;

class Region {
public:
    int region_id;
    std::string region_name;
    htCities* region_cities;  

    Region();
    Region(int id, const std::string& name);
};

class htRegions {
public:
    Region regions[num_reg];
    int hashFunctionRegion(int key);
    void insertRegion(const Region& region);
    Region* getRegion(int regionId);
    void insertCity(int regionId, const City& city); 
};

#endif 
