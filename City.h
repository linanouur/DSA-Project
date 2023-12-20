#ifndef CITY_H
#define CITY_H
<<<<<<< HEAD

#include"customers.h"
#include"customers.cpp"

#include <iostream>
#include <string>
#include"Regions.h"
#include"District.h" 

using namespace std ; 
const int num_cit = 600;

class htDistricts; 
//class Region;

class City {
public: 
=======

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
>>>>>>> 1d383097f4d8713733ac570bdebdf1cfcd48aa86
    City();
    City(int id, const string& name); 
    int CityID;
    string CityName; 
    htDistricts *Districts;   
   
    
 
    string CityName;
    htDistricts *Districts;
    Department department;

    City() : CityID(0), CityName(""), department(0, 100000.00, 0.0) { Districts = new htDistricts;}
    City(int id, const string &name) : CityID(id), CityName(name), department(id, 100000.00, 0.0) {  Districts = new htDistricts;}
};

<<<<<<< HEAD
class htCities {
public: 

    City cities[num_cit];
    int hashFunctionCity(int key); 
    void insertCity(const City& city);
   City * getCity(int cityId);
    void displaycities();  
    
   
=======
class htCities
{
public:
    DepartmentHeap dh;
    City cities[num_cit];
    int hashFunctionCity(int key);
    void insertCity(const City &city);
    City *getCity(int cityId);
    void displaycities();
>>>>>>> 1d383097f4d8713733ac570bdebdf1cfcd48aa86
};

#endif
