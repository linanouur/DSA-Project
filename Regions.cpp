#include "Regions.h"
#include "City.h"

Region::Region() : region_id(0), region_name(""), region_cities(nullptr) {}
Region::Region(int id, const std::string& name) : region_id(id), region_name(name), region_cities(nullptr) {}

int htRegions::hashFunctionRegion(int key) {
    return key % num_reg;
}

void htRegions::insertRegion(const Region& region) {
    int index = hashFunctionRegion(region.region_id);
    regions[index] = region;
}

Region* htRegions::getRegion(int regionId) {
    int index = hashFunctionRegion(regionId);
    return &regions[index];
}

void htRegions::insertCity(int regionId, const City& city) {
    Region* region = getRegion(regionId);
    if (region != nullptr) {
        region->region_cities->insertCity(city, regionId);
    }
}