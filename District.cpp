#include "District.h"
#include "City.h" 
#include "Regions.h"

District::District() : DistrictID(0), DistrictName("") {}
District::District(int id, const std::string& name) : DistrictID(id), DistrictName(name) {}

int htDistricts::hashFunctionDistrict(int key) {
    return key % num_dis;
}

void htDistricts::insertDistrict(const District& district) {
    int index = hashFunctionDistrict(district.DistrictID);
    districts[index] = district;
}

District* htDistricts::getDistrict(int districtId) {
    int index = hashFunctionDistrict(districtId);
    return &districts[index];
}

void htDistricts::insertDistrict(int cityId, const District& district) {
    City* city = getCity(cityId); 
    if (city != nullptr) {
        city->Districts->insertDistrict(district);
    }
}
City* htDistricts::getCity(int cityId) {
    htCities cityHashTable; 
    City* city = cityHashTable.getCity(cityId); 
    return city;
}  

int main()  
{  htRegions regionHashTable; 

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
     cityHashTable.insertCity(city1, 1);  
     cityHashTable.insertCity(city2, 2);  
        districtHashTable.insertDistrict(1, district1);
        districtHashTable.insertDistrict(1, district2); 
        districtHashTable.insertDistrict(2, district3);
        districtHashTable.insertDistrict(2, district4); 
        regionHashTable.displaycities(1); 





    
    return 0 ; 
}
