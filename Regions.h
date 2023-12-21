#ifndef REGION_H
#define REGION_H
#include"City.h"  
#include"District.h" 
#include"customers.h"
// #include"weatherHashTable.h"
#include<iostream>
#include<string>

using namespace std; 

enum class value
{
    empty,
    inserted
};
const int num_reg = 60;
class City;
 class htCities;
class htcities;  

class Region {
public:
    // weatherHashTable tWeather;
    int RegionID;
    string RegionName;
    htCities* Cities;  
    value cas = value::empty;
    Region();
    Region(int id, const string& name);     
    void getOneMonthBillinRegion(int month, int year);  
    void getOneYearBillinRegion(int year);
    void getPeriodBillinRegion(int StartMonth, int StartYear, int EndMonth, int EnDYear);
};

class htRegions {
public:
    Region regions[num_reg];
    int hashFunctionRegion(int key);
    void insertRegion(const Region& region);   
    void insertCity(int regionID , const City &city);
    void insertDistrict(int regionID , int cityID , const District &district);
    Region* getRegion(int RegionID);
    void displaycities(int RegionID); 
    void displayregions();    
    void getOneMonthBillinRegions(int month, int year); 
    void getOneYearBillinRegions(int year);
    void getPeriodBillinRegions(int StartMonth, int StartYear, int EndMonth, int EnDYear);
   
};

#endif 
