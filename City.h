#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

#include"District.h"
#include"customers.h"
#include"customers.cpp"

#include"customer.cpp"

#include"bills.cpp"

using namespace std ; 
const int num_cit = 100;

class htDistricts;
// class Region;

class City {
public:
    int CityID;
    string CityName; 
    htDistricts *Districts;  
    City();
    City(int id, const string& name); 
 
};

class htCities {
public:
    City cities[num_cit];
    int hashFunctionCity(int key); 
    void insertCity(const City& city);
   City * getCity(int cityId);
    void displaycities();
};

#endif 
