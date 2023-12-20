#ifndef CITY_CPP
#define CITY_CPP

#include <iostream>

#include"City.h"
#include"District.h"
#include"customers.h"
using namespace std;
#include <string>
City::City() :CityID (0), CityName("") { 
    Districts = new htDistricts;
}
City::City(int id, const std::string& name) : CityID(id), CityName(name){ 
    Districts = new htDistricts;
}

int htCities::hashFunctionCity(int key) {
    return key % num_cit;
}


void htCities::insertCity(const City& city) {
    int index = hashFunctionCity(city.CityID); 
    if(cities[index].CityID == 0) 
    {
    cities[index] = city; 
    }

} 


City* htCities::getCity(int cityId) {
    int index = hashFunctionCity(cityId);
    return &cities[index]; } 


  void htCities::displaycities(){ 
    for ( int i = 0 ; i < num_cit ; i++){
        if(cities[i].CityID != 0){
            cout <<"name of city " <<cities[i].CityName <<endl;
            cout<<"id of city is "<<cities[i].CityID <<endl;  
        }
        
    }
 }   
 
    // other city data...




#endif