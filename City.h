#ifndef CITY_H
#define CITY_H
#include "Regions.h"
#include "District.h"

#include <iostream>
#include <string>
using namespace std ; 
const int num_cit = 100;

// class htDistricts;
// class Region;

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
    int hashFunctionCity(int key);
    void insertCity(const City& city);
    City* getCity(int CityID);
    void displaycities();
};

#endif 
