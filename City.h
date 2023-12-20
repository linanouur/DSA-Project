#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

#include "District.h"
#include "customers.h"
#include "customers.cpp"
#include "Regions.h"
#include "Departments.h"

using namespace std;
const int num_cit = 100;


enum class valueC
{
    empty,
    inserted
};

class Department;
class DepartmentHeap;
class htDistricts;
// class Region;

class City
{
public:
    int CityID;
    string CityName; 
    htDistricts *Districts;  
    valueC cas = valueC::empty;
    City();
    City(int id, const string& name); 
 
    string CityName;
    htDistricts *Districts;
    Department department;

    City() : CityID(0), CityName(""), department(0, 100000.00, 0.0) { Districts = new htDistricts;}
    City(int id, const string &name) : CityID(id), CityName(name), department(id, 100000.00, 0.0) {  Districts = new htDistricts;}
};

class htCities
{
public:
    DepartmentHeap dh;
    City cities[num_cit];
    int hashFunctionCity(int key);
    void insertCity(const City &city);
    City *getCity(int cityId);
    void displaycities();
};

#endif
