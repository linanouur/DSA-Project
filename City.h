#ifndef CITY_H
#define CITY_H
#include "Regions.h"
#include "District.h"

#include <iostream>
#include <string>

const int num_cit = 100;

class htDistricts;
class Region;

class City {
public:
    int city_id;
    std::string city_name;
    htDistricts* city_disricts;  

    City();
    City(int id, const std::string& name);
};

class htCities {
public:
    City cities[num_cit];
    Region* region;  
    int hashFunctionCity(int key);
    void insertCity(const City& city);
    void insertCity(const City& city, int regionId);
    City* getCity(int cityId);
    Region* getRegion(int regionId);
};

#endif 
