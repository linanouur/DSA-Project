#include <iostream>
using namespace std;
#include <string>
#include "Regions.h" 
#include "District.h"
#include "City.h"

Region::Region() : RegionID(0), RegionName("") { 
    Cities = new htCities;
}
Region::Region(int id, const std::string& name) : RegionID(id), RegionName(name) { 
    Cities = new htCities;
}

int htRegions::hashFunctionRegion(int key) {
    return key % num_reg;
}

void htRegions::insertRegion(const Region& region) {
    int index = hashFunctionRegion(region.RegionID);
    regions[index] = region;
}

Region* htRegions::getRegion(int regionId) {
    int index = hashFunctionRegion(regionId);
    return &regions[index];
}





void htRegions:: displaycities(int RegionID){
    Region* region = getRegion(RegionID);
    if (region != nullptr) {
        region->Cities->displaycities();
    }
}



