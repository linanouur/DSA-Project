#ifndef CITY_H
#define CITY_H 


#include <iostream>
#include <string>
#include"Regions.h"
#include"District.h" 
#include "customers.h"
#include "Regions.h"
#include "Departments.h"

using namespace std;
const int num_cit = 100;





class Department;
class DepartmentHeap;
class htDistricts;
// class Region;

enum class valueC
{
    empty,
    inserted
};
class City
{
public:
    int CityID;
    string CityName; 
    htDistricts *Districts;  
    valueC cas = valueC::empty;
   
    // City(int id, const string& name); 
    Department department;

    City() : CityID(0), CityName(""), department(0, 100000.00, 0.0) { Districts = new htDistricts;}
    City(int id, const string &name) : CityID(id), CityName(name), department(id, 100000.00, 0.0) {  Districts = new htDistricts;} 
    void getOneMonthBillinCity(int month, int year); 
    void getOneYearBillinCity(int year);
    void getPeriodBillinCity(int StartMonth, int StartYear, int EndMonth, int EnDYear);
};


class htCities
{
public:
    DepartmentHeap dh;
    City cities[num_cit];
    int hashFunctionCity(int key); 
    void insertCity(const City& city);
   City * getCityptr(int cityId); 
    City getCity(int cityId);
    void displaycities();  
  


};

#endif
