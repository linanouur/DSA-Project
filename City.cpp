#include "City.h"
#include "Regions.h"
#include "District.h"

City::City() :CityID (0), CityName("") { 
    Districts = new htDistricts;
}
City::City(int id, const std::string& name) : CityID(id), CityName(name){ 
    Districts = new htDistricts;
}

int htCities::hashFunctionCity(int key) {
    return key % num_cit;
}

void htCities::insertCity(const City& city)
{
    int index = hashFunctionCity(city.CityID);
    cities[index] = city;

}
void htCities::insertCity(const City& city, int regionId) {
    int index = hashFunctionCity(city.CityID);
    cities[index] = city;

    region = getRegion(regionId); 
    if (region != nullptr) {
        region->Cities->insertCity(city);
    }
}

City* htCities::getCity(int cityId) {
    int index = hashFunctionCity(cityId);
    return &cities[index];
}

Region* htCities::getRegion(int regionId) {
    htRegions regionhashtable; 
    Region* region = regionhashtable.getRegion(regionId); 
    return region;
} 
  void htCities::displaycities(){ 
    for ( int i = 0 ; i < num_cit ; i++){
        if (cities[i].CityID != 0){
            cout << cities[i].CityName <<cities[i].CityID << endl ;
        }
    }
 }