#ifndef CITY_CPP
#define CITY_CPP

#include <iostream>
#include <string>
#include "City.h"
#include "District.h"
#include "customers.h"

using namespace std;



int htCities::hashFunctionCity(int key)
{
    return key % num_cit;
}

void htCities::insertCity(const City &city)
{
    int index = hashFunctionCity(city.CityID);
    if(cities[index].cas==valueC::empty){
    cities[index].CityID = city.CityID;
    cities[index].CityName = city.CityName;
    cities[index].cas==valueC::inserted;
    dh.insertDepartment(city.department);
    }
    else return;
}


City *htCities::getCity(int cityId)
{
    int index = hashFunctionCity(cityId);
    return &cities[index];
}

void htCities::displaycities()
{
    for (int i = 0; i < num_cit; i++)
    {
         if (cities[i].CityID != 0){
        std::cout<<cities[i].CityName << "  " << cities[i].CityID << endl;
        
    }
} }
void htCities::getOnemonthBillCity(int cityID, int month, int year)
{
    City *city = getCity(cityID);
    if (city != nullptr)
    {
      for(int i=0;i<200;i++){
          if(city->Districts->districts[i].DistrictID!=0){
        city->Districts->districts[i].BST->getOneMonthBillBST(city->Districts->districts[i].DistrictID, month, year);
          }
      }
    }
}
#endif