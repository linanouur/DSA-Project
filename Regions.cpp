#include <iostream>
using namespace std;
#include <string>
#include"Regions.h"
#include"City.h"
#include"City.cpp"
#include"District.h"
#include"District.cpp"
#include"customers.h"
#include"customers.cpp"
#include"customer.h"
#include"calendar.cpp"
#include"bills.h"
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





int main()
{
    htRegions regionHashTable;

    Region region1(1, "Region1");
    Region region2(2, "Region2");
    regionHashTable.insertRegion(region1);
    htDistricts districtHashTable;
    District district1(1, "District1");
    District district2(2, "District2");
    District district3(3, "District3");
    District district4(4, "District4");
    htCities cityHashTable;
    City city1(1, "City1");
    City city2(2, "City2");
    regionHashTable.insertCity(1 , city1);
    regionHashTable.insertCity(2 , city2);
    regionHashTable.insertDistrict(1 , 1 , district1);
    regionHashTable.insertDistrict(1, 1, district2);
    regionHashTable.insertDistrict(2,1, district3);
    regionHashTable.insertDistrict(2,2, district4);
    regionHashTable.displaycities(1);

    return 0;
}
