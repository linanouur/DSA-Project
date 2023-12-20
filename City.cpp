#ifndef CITY_CPP
#define CITY_CPP

#include <iostream>

#include "City.h"
#include "District.h"
#include "customers.h"

using namespace std;

#include <string>

int htCities::hashFunctionCity(int key)
{
    return key % num_cit;
}

void htCities::insertCity(const City &city)
{
    int index = hashFunctionCity(city.CityID);
    if(cities[index].CityID==0){
    cities[index].CityID = city.CityID;
    cities[index].CityName = city.CityName;
    dh.insertDepartment(city.department);
    }
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
        // if (cities[i].CityID != 0){
        cout << cities[i].CityName << "  " << cities[i].CityID << endl;
        // }
    }
}

#endif