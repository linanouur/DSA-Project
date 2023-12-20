#ifndef REGIONS_CPP
#define REGIONS_CPP

 #include <iostream>

#include <string>
#include"Regions.h"
#include"City.h" 
#include "City.cpp"
#include"District.h"
#include"District.cpp"
#include"customers.h"
#include"customers.cpp"
#include"customer.h"
#include"customer.cpp"
#include"calendar.cpp"
#include"bills.h"
using namespace std;
 

Region::Region() : RegionID(0), RegionName("")
{   
    tWeather =  weatherHashTable();
    Cities = new htCities;
}
Region::Region(int id, const std::string &name) : RegionID(id), RegionName(name)
{
    tWeather = weatherHashTable();
    Cities = new htCities;
}

int htRegions::hashFunctionRegion(int key)
{
    return key % num_reg;
}

void htRegions::insertRegion(const Region &region)
{
    int index = hashFunctionRegion(region.RegionID);
    if( regions[index].cas == value::empty){
    regions[index] = region;
    regions[index].cas = value ::inserted;
    }
    else return;
}

Region *htRegions::getRegion(int regionId)
{
    int index = hashFunctionRegion(regionId);
    return &regions[index];
}

void htRegions::displaycities(int RegionID)
{
    Region *region = getRegion(RegionID); 
    cout<<"name of region is "<<region->RegionName <<endl;
    if (region != nullptr)
    {
        region->Cities->displaycities();
    }
}


void htRegions::insertCity(int regionID, const City &city)
{
    Region *region = getRegion(regionID);
    region->Cities->insertCity(city);  
   
   
}

void htRegions::insertDistrict(int regionID, int cityID, const District &district)
{
    Region *region = getRegion(regionID);
    City *city = region->Cities->getCity(cityID);
    city->Districts->insertDistrict(district);
}
   

 void htRegions :: displayregions()  
{ 
    for ( int i = 0 ; i < num_reg ; i++){
        if(regions[i].RegionID != 0){
            cout<<"name of region " <<regions[i].RegionName <<endl; }  } 
}  
void htRegions::getOnemonthBillRegion(int regionID, int month, int year)
{
    Region *region = getRegion(regionID); 
    for ( int i=1; i< num_cit ; i++){
        if(region->Cities->cities[i].CityID != 0){
            region->Cities->getOnemonthBillCity(region->Cities->cities[i].CityID, month, year);
        }
    }
 
}
 

#endif