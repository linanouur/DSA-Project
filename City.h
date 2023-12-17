#ifndef CITY_H
#define CITY_H
#include "Regions.h"
#include "District.h"

#include <iostream>
#include <string>
using namespace std ; 
const int num_cit = 100;

class htDistricts;
class Region;

class City {
public:
    int CityID;
    string CityName;
    htDistricts* Districts;  

    City();
    City(int id, const string& name);
};

class htCities {
public:
    City cities[num_cit];
    Region* region;  
    int hashFunctionCity(int key);
    void insertCity(const City& city);
    void insertCity(const City& city, int RegionID);
    City* getCity(int CityID);
    Region* getRegion(int RegionID); 
   void displaycities();
};

#endif 
