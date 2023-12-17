#include "City.h"
#include "Regions.h"
#include "District.h"

City::City() : city_id(0), city_name(""), city_disricts(nullptr) {}
City::City(int id, const std::string& name) : city_id(id), city_name(name), city_disricts(nullptr) {}

int htCities::hashFunctionCity(int key) {
    return key % num_cit;
}

void htCities::insertCity(const City& city)
{
    int index = hashFunctionCity(city.city_id);
    cities[index] = city;

}
void htCities::insertCity(const City& city, int regionId) {
    int index = hashFunctionCity(city.city_id);
    cities[index] = city;

    region = getRegion(regionId); 
    if (region != nullptr) {
        region->region_cities->insertCity(city);
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