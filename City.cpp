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
        // if (cities[i].CityID != 0){
        cout << cities[i].CityName << "  " << cities[i].CityID << endl;
        // }
    }
}

#endif